// #include <linux/types.h>

#define PROMISC_MODE_ON 1 // флаг включения неразборчивый режим
#define PROMISC_MODE_OFF 0 // флаг выключения неразборчивого режима

struct ifparam
{
    __u32		ip;	// IP адрес
    __u32 		mask;	// маска подсети
    int 		mtu;	// размер MTU
    int 		index;	// индекс интерфейса
} ifp;









