set(CPU -mcpu=cortex-m0)
set(FPU )
set(FLOAT_ABI )

set(CPU_COMPILE_OPTIONS 
	${CPU}
	-mthumb
	${FPU}
	${FLOAT_ABI}
)
