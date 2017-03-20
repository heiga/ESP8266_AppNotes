
module trolley_system (
	altpll_0_c1_clk,
	button_button_external_connection_export,
	button_led_external_connection_export,
	cam_uart_external_connection_rxd,
	cam_uart_external_connection_txd,
	clk_clk,
	epcs_flash_controller_0_external_dclk,
	epcs_flash_controller_0_external_sce,
	epcs_flash_controller_0_external_sdo,
	epcs_flash_controller_0_external_data0,
	green_leds_external_connection_export,
	key_external_connection_export,
	motor_l_external_connection_export,
	motor_r_external_connection_export,
	prox_sensor_external_connection_export,
	reset_reset_n,
	sdram_controller_0_wire_addr,
	sdram_controller_0_wire_ba,
	sdram_controller_0_wire_cas_n,
	sdram_controller_0_wire_cke,
	sdram_controller_0_wire_cs_n,
	sdram_controller_0_wire_dq,
	sdram_controller_0_wire_dqm,
	sdram_controller_0_wire_ras_n,
	sdram_controller_0_wire_we_n,
	speaker_external_connection_export,
	wifi_uart_external_connection_rxd,
	wifi_uart_external_connection_txd);	

	output		altpll_0_c1_clk;
	input		button_button_external_connection_export;
	output		button_led_external_connection_export;
	input		cam_uart_external_connection_rxd;
	output		cam_uart_external_connection_txd;
	input		clk_clk;
	output		epcs_flash_controller_0_external_dclk;
	output		epcs_flash_controller_0_external_sce;
	output		epcs_flash_controller_0_external_sdo;
	input		epcs_flash_controller_0_external_data0;
	output	[7:0]	green_leds_external_connection_export;
	input		key_external_connection_export;
	output	[2:0]	motor_l_external_connection_export;
	output	[2:0]	motor_r_external_connection_export;
	input		prox_sensor_external_connection_export;
	input		reset_reset_n;
	output	[11:0]	sdram_controller_0_wire_addr;
	output	[1:0]	sdram_controller_0_wire_ba;
	output		sdram_controller_0_wire_cas_n;
	output		sdram_controller_0_wire_cke;
	output		sdram_controller_0_wire_cs_n;
	inout	[15:0]	sdram_controller_0_wire_dq;
	output	[1:0]	sdram_controller_0_wire_dqm;
	output		sdram_controller_0_wire_ras_n;
	output		sdram_controller_0_wire_we_n;
	output		speaker_external_connection_export;
	input		wifi_uart_external_connection_rxd;
	output		wifi_uart_external_connection_txd;
endmodule
