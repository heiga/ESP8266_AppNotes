-- Randy Baron and Phillip Huang
-- Top level for robot trolley project ECE492 w2017

library ieee;

-- Commonly imported packages:

	-- STD_LOGIC and STD_LOGIC_VECTOR types, and relevant functions
	use ieee.std_logic_1164.all;

	-- SIGNED and UNSIGNED types, and relevant functions
	use ieee.numeric_std.all;

	-- Basic sequential functions and concurrent procedures
	use ieee.VITAL_Primitives.all;
	
	-- Dimensions for logic busses used by the FPGA
	use work.DE0_CONSTANTS.all;
	
	entity ECE492_g7_2017w_WAT is
	
	port
	(
		-- Input ports and 50 MHz Clock
		CLOCK_50	: in  std_logic;
		KEY		: in  std_logic_vector(1 downto 0);
		GPIO_0   : inout  DE0_GPIO; --Temp size and allocations until peripherals connected
		
		-- SDRAM on board
		--DRAM_ADDR
		DRAM_ADDR	:	out	DE0_SDRAM_ADDR_BUS;
		DRAM_BA	   : 	out	std_logic_vector(1 downto 0);
		DRAM_CAS_N	:	out	std_logic;
		DRAM_CKE		:	out	std_logic;
		DRAM_CLK		:	out	std_logic;
		DRAM_CS_N	:	out	std_logic;
		--DRAM_DQ
		DRAM_DQ		:	inout DE0_SDRAM_DATA_BUS;
		DRAM_DQM	   : 	out	std_logic_vector(1 downto 0);
		DRAM_RAS_N	: 	out	std_logic;
		DRAM_WE_N	: 	out 	std_logic;
		
		--LEDs
		LED        :  out  std_logic_vector(7 downto 0);
		
		--Flash
		EPCS_ASDO	:	out std_logic;
		EPCS_DATA0	:	in std_logic;
	   EPCS_DCLK	:	out std_logic;
		EPCS_NCSO	:	out std_logic
		
	);
end ECE492_g7_2017w_WAT;

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity speakerinterface is
	port 
	(
	clk : in std_logic;
	ena : in std_logic;
	tospeaker : out std_logic);
end speakerinterface;

architecture speak of speakerinterface is
	signal x: std_logic_vector(0 to 15) := x"0000";
	signal output : std_logic := '0';
	
	
	begin 
	tospeaker <= output;	
	process (clk, ena)
	
		begin
		if(rising_edge(clk)) then
			if x = x"61A8" then
			output <= not output;
			x <= x"0000";
			end if;
		
			if ena = '1' then
			x <= x + 1;
			end if;
		end if;		
	end process;	
end speak;


architecture structure of ECE492_g7_2017w_WAT is

	-- Declarations (optional)
	signal enable	: std_logic;
	--signal dummy 	: std_logic;

	component trolley_system is
		port (
			clk_clk                         : in    std_logic                     := 'X';   -- clk
			reset_reset_n                   : in    std_logic                     := 'X';   -- reset_n
			altpll_0_c1_clk					  : out   std_logic;
			sdram_controller_0_wire_addr    : out   DE0_SDRAM_ADDR_BUS;                     -- addr
			sdram_controller_0_wire_ba      : out   std_logic_vector(1 downto 0);           -- ba
			sdram_controller_0_wire_cas_n   : out   std_logic;                              -- cas_n
			sdram_controller_0_wire_cke     : out   std_logic;                              -- cke
			sdram_controller_0_wire_cs_n    : out   std_logic;                              -- cs_n
			sdram_controller_0_wire_dq      : inout DE0_SDRAM_DATA_BUS := (others => 'X');  -- dq
			sdram_controller_0_wire_dqm     : out   std_logic_vector(1 downto 0);           -- dqm
			sdram_controller_0_wire_ras_n   : out   std_logic;                              -- ras_n
			sdram_controller_0_wire_we_n    : out   std_logic;                              -- we_n
			cam_uart_external_connection_rxd    : in    std_logic                     := 'X';   -- rxd
			cam_uart_external_connection_txd    : out   std_logic;                               -- txd
			wifi_uart_external_connection_rxd      : in    std_logic                     := 'X';             -- rxd
			wifi_uart_external_connection_txd      : out   std_logic;                                        -- txd
			prox_sensor_external_connection_export : in    std_logic                     := 'X';             -- export
			motor_r_external_connection_export     : out   std_logic_vector(2 downto 0);                     -- export
			motor_l_external_connection_export     : out   std_logic_vector(2 downto 0);                     -- export
			green_leds_external_connection_export  : out   std_logic_vector(7 downto 0);                      -- export
			button_button_external_connection_export : in    std_logic                     := 'X';             -- export
			speaker_external_connection_export       : out   std_logic;                                        -- export
			button_led_external_connection_export    : out   std_logic;                                         -- export
			key_external_connection_export			  : in    std_logic;
			epcs_flash_controller_0_external_dclk    : out   std_logic;                                        -- dclk
			epcs_flash_controller_0_external_sce     : out   std_logic;                                        -- sce
			epcs_flash_controller_0_external_sdo     : out   std_logic;                                        -- sdo
			epcs_flash_controller_0_external_data0   : in    std_logic                     := 'X'              -- data0
		);
	end component trolley_system;
--	These signals are for matching the provided IP core to
-- The specific SDRAM chip in our system	 
--	signal BA	: std_logic_vector (1 downto 0);
--	signal DQM	:	std_logic_vector (1 downto 0);
	 
	component speakerinterface is 
		port (
			clk : in std_logic;
			ena : in std_logic;
			tospeaker : out std_logic);
	end component speakerinterface;

begin

--	DRAM_BA(1)  <= BA(1);
--	DRAM_BA(0)  <= BA(0);
--	
--	DRAM_DQM(1) <= DQM(1);
--	DRAM_DQM(0) <= DQM(0);
	
-- FL_RST_N(0) <= 'H';
		
		
	u0 : component trolley_system
		port map (
			clk_clk                                  => CLOCK_50,    
			reset_reset_n                            => KEY(0), 
			altpll_0_c1_clk                          => DRAM_CLK,
		   sdram_controller_0_wire_addr             => DRAM_ADDR,                      
         sdram_controller_0_wire_ba               => DRAM_BA,                        
         sdram_controller_0_wire_cas_n            => DRAM_CAS_N,                      
         sdram_controller_0_wire_cke              => DRAM_CKE,                       
         sdram_controller_0_wire_cs_n             => DRAM_CS_N,                      
         sdram_controller_0_wire_dq               => DRAM_DQ,                         
         sdram_controller_0_wire_dqm              => DRAM_DQM,                        
         sdram_controller_0_wire_ras_n            => DRAM_RAS_N,                     
         sdram_controller_0_wire_we_n             => DRAM_WE_N,    
			cam_uart_external_connection_rxd         => GPIO_0(4),   
			cam_uart_external_connection_txd         => GPIO_0(2),
			wifi_uart_external_connection_rxd        => GPIO_0(0),
			wifi_uart_external_connection_txd        => GPIO_0(3),
			prox_sensor_external_connection_export   => NOT(GPIO_0(30)),
			motor_r_external_connection_export(0)    => GPIO_0(11), --APWM
			motor_r_external_connection_export(1)    => GPIO_0(12), --A1
			motor_r_external_connection_export(2)    => GPIO_0(15), --A2
			motor_l_external_connection_export(0)    => GPIO_0(20), --BPWM
			motor_l_external_connection_export(1)    => GPIO_0(16), --B1
			motor_l_external_connection_export(2)    => GPIO_0(19), --B2
			green_leds_external_connection_export    => LED,
			button_button_external_connection_export => NOT(GPIO_0(25)), 
			speaker_external_connection_export       => enable,       
			button_led_external_connection_export    => GPIO_0(26),
			key_external_connection_export           => KEY(1),
			epcs_flash_controller_0_external_dclk    => EPCS_DCLK,
			epcs_flash_controller_0_external_sce     => EPCS_NCSO,     
			epcs_flash_controller_0_external_sdo     => EPCS_ASDO,
			epcs_flash_controller_0_external_data0   => EPCS_DATA0   
		);
		
	u1 : component speakerinterface
		port map (
			clk => CLOCK_50,
			ena => enable,
			tospeaker => GPIO_0(29)
		);

end structure;

library ieee;

	-- STD_LOGIC and STD_LOGIC_VECTOR types, and relevant functions
	use ieee.std_logic_1164.all;

package DE0_CONSTANTS is

	type DE0_GPIO is array(33 downto 0) of std_logic;
	
	type DE0_SDRAM_ADDR_BUS is array(11 downto 0) of std_logic;
	type DE0_SDRAM_DATA_BUS is array(15 downto 0) of std_logic;
	
end DE0_CONSTANTS;



