#include <stdio.h>
#include <stdlib.h>
#include "opencl.h"

/* 
* Note - The error messages will be thrown up later so main can display them or a QT/GTK etc etc UI can display them 
*/



void OpenCLGetDeviceData(cl_device_id* Device, deviceData* DeviceData)
{
	opencl_error = clGetDeviceInfo(*Device, CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(cl_ulong), &DeviceData->max_memory, NULL);
	if(opencl_error == CL_SUCCESS)
	{
		/* 
		 * Fill devicedata with information we are interested in 
		*/
	}
	else if(opencl_error == CL_INVALID_DEVICE)
	{
		printf(" The device is invalid. Failed to query information\n");
	}
	else if(opencl_error == CL_INVALID_VALUE)
	{
		printf(" The query was invalid, A paramater is not valid\n");
	}
	else
	{
		DeviceData -> max_memory = 0;
		printf("Failed to query maximum allocation size on the compute device\n");
	}

}


int OpenCLInit()
{
	deviceData info;
		
	/* Setup the OpenCL Platform */
	opencl_error = clGetPlatformIDs(1, &opencl_platform, NULL);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to get the platform id\n");	
		return EXIT_FAILURE;
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
		return EXIT_FAILURE;
	}
	
	
	/* Setup the OpenCL Context */
	opencl_context = clCreateContext(0, 1, &opencl_device, NULL, NULL, &opencl_error);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to create an OpenCL context\n");
		return EXIT_FAILURE;
	}
	
	/* Setup the OpenCL Command Queue */
	opencl_command_queue = clCreateCommandQueue(opencl_context, opencl_device, 0, &opencl_error);
	if(opencl_error != CL_SUCCESS)
	{
		printf("Failed to create OpenCL Command queue\n");
		return EXIT_FAILURE;
	}
	
	/* 
	* Find out some applicable information about the opencl devices that are available which
	  can help us determine how large each chunk of a file can be processed each time
	  (The size of the chunk of data that gets copied to the GPU/CPU or other device)
	*/
	
	OpenCLGetDeviceData(&opencl_device,&info);
	
	
	/* Set global engine options based upon what info contains */
	
	return 0;
	
	
}



void OpenCLFree()
{
	clReleaseCommandQueue(opencl_command_queue);
	clReleaseContext(opencl_context);
}




