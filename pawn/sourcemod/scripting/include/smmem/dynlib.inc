#if defined _smmem_dynlib_included
	#endinput
#endif
#define _smmem_dynlib_included

#include <smmem>

methodmap DynLib < Handle
{
	/**
	 *	Load a running dynamic library (.dll/.so)
	 *
	 *	@param name 			Name of the library to open.
	 *							Exclude file extensions (.dll/.so).
	 *							The extension adds those automatically.
	 *							Linux must have the correct path to the 
	 *							library file. Starts in srcds directory.
	 *
	 *	@return 				Handle to new DynLib object. Must be freed 
	 *							with delete/CloseHandle
	*/
	public native DynLib(const char[] name);

	/**
	 *	Retrieve the base address of the file in memory.
	*/
	property Address BaseAddr
	{
		public native get();
	}

	/**
	 *	Get the name of the loaded library.
	 *
	 *	@param buffer 			String buffer.
	 *	@param len 				Buffer length.
	*/
	public native void GetName(char[] buffer, int len);

	/**
	 *	Find a pattern of bytes in a library AKA sigscan.
	 *
	 *	@param pattern 			String of bytes.
	 *	@param len 				Length of string.
	 *
	 *	@return 				Address of the found pattern, Address_Null
	 * 							if not found.
	*/
	public native Address FindPattern(const char[] pattern, int len);

	/**
	 *	Find the address of a symbol in a library
	 *
	 *	@param sym 				Symbol to find, does not need to start with '@'.
	 *
	 *	@return 				Address of the symbol if found, Address_Null
	 * 							otherwise.
	*/
	public native Address ResolveSymbol(const char[] sym);
};