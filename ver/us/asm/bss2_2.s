.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .bss

dlabel wPartnerTetherDistance
.space 4

dlabel D_8010CFC4
.space 4

dlabel wPartnerFollowState
.space 2

dlabel D_8010CFCA
.space 2

dlabel D_8010CFCC
.space 2

dlabel D_8010CFCE
.space 2

dlabel wPartnerNpcIndex
.space 4

dlabel wPartnerCurrentScript
.space 4

dlabel wCurrentPartnerId
.space 4

dlabel wPartnerCurrentScriptID
.space 4

dlabel D_8010CFE0
.space 4

dlabel NextPartnerID
.space 4

dlabel NextPartnerCommand
.space 4

dlabel wPartner
.space 4

dlabel D_8010CFF0
.space 4

dlabel D_8010CFF4
.space 4

dlabel D_8010CFF8
.space 8

dlabel D_8010D000
.space 4

dlabel D_8010D004
.space 0x63C

dlabel D_8010D640
.space 4

dlabel D_8010D644
.space 4

dlabel D_8010D648
.space 4

dlabel D_8010D64C
.space 4

dlabel D_8010D650
.space 4

dlabel D_8010D654
.space 1

dlabel D_8010D655
.space 1

dlabel D_8010D656
.space 2

dlabel D_8010D658
.space 2

dlabel D_8010D65A
.space 2

dlabel D_8010D65C
.space 4

dlabel D_8010D660
.space 4

dlabel D_8010D664
.space 4

dlabel D_8010D668
.space 4

dlabel D_8010D66C
.space 4

dlabel D_8010D670
.space 4

dlabel D_8010D674
.space 4

dlabel D_8010D678
.space 4

dlabel D_8010D67C
.space 2

dlabel D_8010D67E
.space 2

dlabel D_8010D680
.space 2

dlabel D_8010D682
.space 2

dlabel D_8010D684
.space 2

dlabel D_8010D686
.space 2

dlabel D_8010D688
.space 2

dlabel D_8010D68A
.space 2

dlabel D_8010D68C
.space 2

dlabel D_8010D68E
.space 1

dlabel D_8010D68F
.space 1

dlabel D_8010D690
.space 1

dlabel D_8010D691
.space 1

dlabel D_8010D692
.space 1

dlabel D_8010D693
.space 1

dlabel D_8010D694
.space 4

dlabel D_8010D698
.space 1

dlabel D_8010D699
.space 1

dlabel D_8010D69A
.space 2

dlabel gPopupMenu
.space 4

dlabel D_8010D6A0
.space 4

dlabel D_8010D6A4
.space 4

dlabel D_8010D6A8
.space 0x8

dlabel gBoxQuadBuffer
.space 0x1500

dlabel gPartnerActionStatus
.space 0x360

dlabel gSpinHistoryPosY
.space 0x18

dlabel gSpinHistoryPosX
.space 0x18

dlabel gSpinHistoryPosZ
.space 0x18

dlabel gUIStatus
.space 0x70

dlabel gPlayerStatus
.space 0x288

dlabel gPlayerSpinState
.space 0x34

dlabel D_8010F284
.space 0xC

dlabel gPlayerData
.space 0x428

dlabel gSpinHistoryPosAngle
.space 0x10
