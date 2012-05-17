#include <OpenCL/OpenCL.h>

cl_int opencl_error;
cl_platform_id opencl_platform;
cl_context opencl_context;
cl_command_queue opencl_command_queue;
cl_device_id opencl_device;
cl_mem opencl_buffer;

/* clGetDeviceInfo will will help me populate this struct with information I'm interested in */
typedef struct
{
	char* name;
	cl_ulong max_memory;
	
} deviceData;

void OpenCLGetDeviceData(cl_device_id* Device, deviceData* DeviceData);
int OpenCLInit();
void OpenCLFree();


