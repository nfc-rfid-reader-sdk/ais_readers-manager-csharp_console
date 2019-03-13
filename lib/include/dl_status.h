/*
 * dl_status.h
 *
 *  Created on: 08.11.2013.
 *      Author: Digital Logic, www.d-logic.net
 */
#ifndef DL_STATUS_H_
#define DL_STATUS_H_

//#define DL_SUCCESS(status) ((status) == DL_OK)
//#define DL_FAILURE(status) ((status) != DL_OK)
//#define DL_TIME_OUT(status)((status) == TIMEOUT_ERROR)

/// @brief Specifies error handler values for the functions.
typedef enum E_ERROR_CODES
{
	DL_OK = 0x00, /// Command is executed successfully

	//###############################################################
	// common - mostly used
	TIMEOUT_ERROR, /// Repeat command

	NULL_POINTER, /// TODO: Check command arguments
	PARAMETERS_ERROR,

	MEMORY_ALLOCATION_ERROR,

	NOT_INITIALIZED,
	ALREADY_INITIALIZED,

	TIMESTAMP_INVALID,

	EVENT_BUSY,

	//###############################################################
	// specific = 0x1000
	ERR_SPECIFIC = 0x1000,
	// USB RF
	CMD_BRAKE_RTE, // RTE arrived while CMD_IN_PROGRESS

	TRANSFER_ACK_FAILED, // transfer acknowledge failed
	NO_RF_PACKET_DATA, /// no data; TODO: retry RF packet

	TRANSFER_WRITING_ERROR, /// error while transfer file

	EVENT_WAKEUP_BUSY,

	DEVICE_RESET_OCCURRED,

	//###############################################################
	// resource = 0x2000
	RESOURCE_NOT_ACQUIRED = 0x2000,
	RESOURCE_ALREADY_ACQUIRED,
	RESOURCE_BUSY,
	RESOURCE_NOT_OWNER,

	//###############################################################
	// FILE = 0x3000
	FILE_OVERSIZE = 0x3000, /// Provided file is too big
	FILE_EMPTY, /// Provided file is empty
	FILE_LOCKED, /// File is locked, and still unread; when file is fill, and not read yet
	FILE_NOT_FOUND,
	ERR_NO_FILE_NAME,
	ERR_DIR_CAN_NOT_CREATE,
	ERR_FILE_NOT_CORRECT,

	//###############################################################
	// LOG = 0x4000 // data validity
	ERR_DATA = 0x4000,
	ERR_BUFFER_EMPTY,    ///< 0x4001
	ERR_BUFFER_OVERFLOW, ///< 0x4002
	ERR_CHECKSUM, // CRC ERROR
	LOG_NOT_CORRECT,

	//###############################################################
//	0x5000,

	//###############################################################
//	0x6000,

	//###############################################################
	// list operations = 0x7000
	LIST_ERROR = 0x7000,
	ITEM_IS_ALREADY_IN_LIST,
	ITEM_NOT_IN_LIST,
	ITEM_NOT_VALID,

	//###############################################################
	// devices = 0x8000
	NO_DEVICES = 0x8000, // NO_USB_RF_DEVICES
	//###############################################################
	// open multiple devices
	DEVICE_OPENING_ERROR,
	DEVICE_CAN_NOT_OPEN,
	DEVICE_ALREADY_OPENED,
	DEVICE_NOT_OPENED,
	DEVICE_WRONG_HANDLE_ERROR,
	DEVICE_CLOSE_ERROR,
	DEVICE_UNKNOWN,
	DEVICE_NOT_SUPPORTED,

	//###############################################################
	// command response = 0x9000
	ERR_COMMAND_RESPONSE = 0x9000,
	CMD_RESPONSE_UNKNOWN_COMMAND,
	CMD_RESPONSE_WRONG_CMD,
	CMD_RESPONSE_COMMAND_FAILED,
	CMD_RESPONSE_UNSUCCESS, /// TODO: try again
	CMD_RESPONSE_NO_AUTHORIZATION,
	CMD_RESPONSE_SIZE_OVERFLOW,
	CMD_RESPONSE_NO_DATA,

	//###############################################################
	// Threads and objects = 0xA000
	THREAD_FAILURE = 0xA000,
	//---------------------
	ERR_OBJ_NOT_CREATED,
	//---------------------
	ERR_CREATE_SEMAPHORE,

	//###############################################################
	// state machines = 0xB000
	ERR_STATE_MACHINE = 0xB000,
	ERR_SM_IDLE__NO_RESPONSE, /// Result of the chained command is a empty or already get in application.
	ERR_SM_COMMAND_IN_PROGRESS, /// TODO: Execute main_loop()
	ERR_SM_NOT_IDLE, /// Wait for information about previous command, executing main_loop (repeat command)
	ERR_SM_CMD_NOT_STARTED,
	WARN_STOP_POLLING,

	//###############################################################
	// readers errors = 0xD000
	READER_ERRORS_ = 0xD000,
	READER_UID_ERROR,
	READER_LOG_ERROR,

	//###############################################################
	// HAMMING = 0xE000
	DL_HAMMING_ERROR = 0xE000,
	DL_HAMMING_NOT_ACK,
	DL_HAMMING_WRONG_ACK,
	DL_HAMMING_WRONG_REPLAY,

	ERROR_SOME_REPLAY_FAULT,

	//  Formatted transfer
	DL_HAMMING_TERR_TIMEOUT,
	DL_HAMMING_TERR_BAD_FRAME,
	DL_HAMMING_TERR_BAD_SUM,
	DL_HAMMING_TERR_BAD_CODE,
	DL_HAMMING_TERR_TOO_OLD,
	DL_HAMMING_TERR_NOISE, // Warning returned by DecodeFrame()
	DL_HAMMING_TERR_ERROR_MASK,

	//###############################################################
	// FTDI = 0xF000
	NO_FTDI_COMM_DEVICES = 0xF000,
	NO_FTDI_COMM_DEVICES_OPENED,

	ERR_FTDI, // global
	ERR_FTDI_READ, /// Can't read data from communication interface
	ERR_FTDI_READ_LESS_DATA, /// less data read from communication interface
	ERR_FTDI_WRITE, /// Can't write data to communication interface
	ERR_FTDI_WRITE_LESS_DATA,

	DL_FT_ERROR_SET_TIMEOUT,

	// FTSTATUS
	DL_FT_ = 0xF100,
	DL_FT_INVALID_HANDLE,
	DL_FT_DEVICE_NOT_FOUND,
	DL_FT_DEVICE_NOT_OPENED,
	DL_FT_IO_ERROR,
	DL_FT_INSUFFICIENT_RESOURCES,
	DL_FT_INVALID_PARAMETER,
	DL_FT_INVALID_BAUD_RATE,

	DL_FT_DEVICE_NOT_OPENED_FOR_ERASE,
	DL_FT_DEVICE_NOT_OPENED_FOR_WRITE,
	DL_FT_FAILED_TO_WRITE_DEVICE,
	DL_FT_EEPROM_READ_FAILED,
	DL_FT_EEPROM_WRITE_FAILED,
	DL_FT_EEPROM_ERASE_FAILED,
	DL_FT_EEPROM_NOT_PRESENT,
	DL_FT_EEPROM_NOT_PROGRAMMED,
	DL_FT_INVALID_ARGS,
	DL_FT_NOT_SUPPORTED,
	DL_FT_OTHER_ERROR,
	DL_FT_DEVICE_LIST_NOT_READY,

	//---------------------
	NOT_IMPLEMENTED = 0xFFFFFFFE, // -2
	//---------------------
	UNKNOWN_ERROR = 0xFFFFFFFF, // -1

	MAX_DL_STATUS = 0xFFFFFFFF, // -1
	LAST_ERROR = 0xFFFFFFFF
} DL_STATUS;

//#ifndef DL_API
//#	define DL_API
//#	define UNDEF_DL_API
//#endif

//DL_API
const char * DL_STATUS2Str(DL_STATUS status);

// try in API:
// const char * DL_Status2Str(DL_STATUS status);

//DL_API
const char * prn_status(DL_STATUS dl_status, const char * pre_msg/* = 0*/);

//#ifdef UNDEF_DL_API
//#	undef DL_API
//#	undef UNDEF_DL_API
//#endif

#endif /* DL_STATUS_H_ */
