#include <OpenCL/OpenCL.h>

cl_int opencl_error;
cl_platform_id opencl_platform;
cl_context opencl_context;
cl_command_queue opencl_command_queue;
cl_device_id opencl_device;

int OpenCLInit();
void OpenCLFree();

