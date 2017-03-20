	component trolley_system is
		port (
			altpll_0_c1_clk                          : out   std_logic;                                        -- clk
			button_button_external_connection_export : in    std_logic                     := 'X';             -- export
			button_led_external_connection_export    : out   std_logic;                                        -- export
			cam_uart_external_connection_rxd         : in    std_logic                     := 'X';             -- rxd
			cam_uart_external_connection_txd         : out   std_logic;                                        -- txd
			clk_clk                                  : in    std_logic                     := 'X';             -- clk
			epcs_flash_controller_0_external_dclk    : out   std_logic;                                        -- dclk
			epcs_flash_controller_0_external_sce     : out   std_logic;                                        -- sce
			epcs_flash_controller_0_external_sdo     : out   std_logic;                                        -- sdo
			epcs_flash_controller_0_external_data0   : in    std_logic                     := 'X';             -- data0
			green_leds_external_connection_export    : out   std_logic_vector(7 downto 0);                     -- export
			key_external_connection_export           : in    std_logic                     := 'X';             -- export
			motor_l_external_connection_export       : out   std_logic_vector(2 downto 0);                     -- export
			motor_r_external_connection_export       : out   std_logic_vector(2 downto 0);                     -- export
			prox_sensor_external_connection_export   : in    std_logic                     := 'X';             -- export
			reset_reset_n                            : in    std_logic                     := 'X';             -- reset_n
			sdram_controller_0_wire_addr             : out   std_logic_vector(11 downto 0);                    -- addr
			sdram_controller_0_wire_ba               : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_controller_0_wire_cas_n            : out   std_logic;                                        -- cas_n
			sdram_controller_0_wire_cke              : out   std_logic;                                        -- cke
			sdram_controller_0_wire_cs_n             : out   std_logic;                                        -- cs_n
			sdram_controller_0_wire_dq               : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_controller_0_wire_dqm              : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_controller_0_wire_ras_n            : out   std_logic;                                        -- ras_n
			sdram_controller_0_wire_we_n             : out   std_logic;                                        -- we_n
			speaker_external_connection_export       : out   std_logic;                                        -- export
			wifi_uart_external_connection_rxd        : in    std_logic                     := 'X';             -- rxd
			wifi_uart_external_connection_txd        : out   std_logic                                         -- txd
		);
	end component trolley_system;

	u0 : component trolley_system
		port map (
			altpll_0_c1_clk                          => CONNECTED_TO_altpll_0_c1_clk,                          --                       altpll_0_c1.clk
			button_button_external_connection_export => CONNECTED_TO_button_button_external_connection_export, -- button_button_external_connection.export
			button_led_external_connection_export    => CONNECTED_TO_button_led_external_connection_export,    --    button_led_external_connection.export
			cam_uart_external_connection_rxd         => CONNECTED_TO_cam_uart_external_connection_rxd,         --      cam_uart_external_connection.rxd
			cam_uart_external_connection_txd         => CONNECTED_TO_cam_uart_external_connection_txd,         --                                  .txd
			clk_clk                                  => CONNECTED_TO_clk_clk,                                  --                               clk.clk
			epcs_flash_controller_0_external_dclk    => CONNECTED_TO_epcs_flash_controller_0_external_dclk,    --  epcs_flash_controller_0_external.dclk
			epcs_flash_controller_0_external_sce     => CONNECTED_TO_epcs_flash_controller_0_external_sce,     --                                  .sce
			epcs_flash_controller_0_external_sdo     => CONNECTED_TO_epcs_flash_controller_0_external_sdo,     --                                  .sdo
			epcs_flash_controller_0_external_data0   => CONNECTED_TO_epcs_flash_controller_0_external_data0,   --                                  .data0
			green_leds_external_connection_export    => CONNECTED_TO_green_leds_external_connection_export,    --    green_leds_external_connection.export
			key_external_connection_export           => CONNECTED_TO_key_external_connection_export,           --           key_external_connection.export
			motor_l_external_connection_export       => CONNECTED_TO_motor_l_external_connection_export,       --       motor_l_external_connection.export
			motor_r_external_connection_export       => CONNECTED_TO_motor_r_external_connection_export,       --       motor_r_external_connection.export
			prox_sensor_external_connection_export   => CONNECTED_TO_prox_sensor_external_connection_export,   --   prox_sensor_external_connection.export
			reset_reset_n                            => CONNECTED_TO_reset_reset_n,                            --                             reset.reset_n
			sdram_controller_0_wire_addr             => CONNECTED_TO_sdram_controller_0_wire_addr,             --           sdram_controller_0_wire.addr
			sdram_controller_0_wire_ba               => CONNECTED_TO_sdram_controller_0_wire_ba,               --                                  .ba
			sdram_controller_0_wire_cas_n            => CONNECTED_TO_sdram_controller_0_wire_cas_n,            --                                  .cas_n
			sdram_controller_0_wire_cke              => CONNECTED_TO_sdram_controller_0_wire_cke,              --                                  .cke
			sdram_controller_0_wire_cs_n             => CONNECTED_TO_sdram_controller_0_wire_cs_n,             --                                  .cs_n
			sdram_controller_0_wire_dq               => CONNECTED_TO_sdram_controller_0_wire_dq,               --                                  .dq
			sdram_controller_0_wire_dqm              => CONNECTED_TO_sdram_controller_0_wire_dqm,              --                                  .dqm
			sdram_controller_0_wire_ras_n            => CONNECTED_TO_sdram_controller_0_wire_ras_n,            --                                  .ras_n
			sdram_controller_0_wire_we_n             => CONNECTED_TO_sdram_controller_0_wire_we_n,             --                                  .we_n
			speaker_external_connection_export       => CONNECTED_TO_speaker_external_connection_export,       --       speaker_external_connection.export
			wifi_uart_external_connection_rxd        => CONNECTED_TO_wifi_uart_external_connection_rxd,        --     wifi_uart_external_connection.rxd
			wifi_uart_external_connection_txd        => CONNECTED_TO_wifi_uart_external_connection_txd         --                                  .txd
		);

