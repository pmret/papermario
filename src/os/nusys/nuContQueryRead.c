#include "common.h"
#include "nu/nusys.h"

void nuContQueryRead(void) {
    nuSiSendMesg(NU_CONT_QUERY_MSG, NULL);
}
