#include <stdio.h>
#include "opencl.h"

/* Note - The error messages will be thrown up later so main can display them or a QT/GTK etc etc UI can display them */

int OpenCLInit()
{

	/* Setup the OpenCL Platform */
	opencl_error = clGetPlatformIDs(1, &opencl_platform, NULL);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to get the platform id\n");	
		return -1;
	}
	
	/* 
	* Setup the OpenCL Device
	* Find out if there are CL_DEVICE_TYPE_ANY and enumerate through all available devices. 
	* I'm not sure if at this stage I'll be using OpenCL for the CPU as well or a different posix threads code path 
	*/
	opencl_error = clGetDeviceIDs(opencl_platform, CL_DEVICE_TYPE_GPU, 1, &opencl_device, NULL);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to get the device id\n");
		return -1;
	}
	
	/* Setup the OpenCL Context */
	opencl_context = clCreateContext(0, 1, &opencl_device, NULL, NULL, &opencl_error);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to create an OpenCL context\n");
		return -1;
	}
	
	/* Setup the OpenCL Command Queue */
	opencl_command_queue = clCreateCommandQueue(opencl_context, opencl_device, 0, &opencl_error);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to create OpenCL Command queue\n");
		return -1;
	}
	return 0;
}

void OpenCLFree()
{
	clReleaseCommandQueue(opencl_command_queue);
	clReleaseContext(opencl_context);
}




