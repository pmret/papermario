.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

#ifndef SHIFT

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
.space 0x63C

dlabel D_8010D63C
.space 0x4

dlabel gPopupState
.space 4

dlabel D_8010D644
.space 4

dlabel PopupMenu_SelectedIndex
.space 4

dlabel PopupMenu_PrevSelectedIndex
.space 4

dlabel PopupMenu_Alpha
.space 4

dlabel PopupMenu_FirstDisplayIndex
.space 1

dlabel PopupMenu_LastDisplayIndex
.space 1

dlabel PopupMenu_DisplayedEntryCount
.space 2

dlabel D_8010D658
.space 2

dlabel D_8010D65A
.space 2

dlabel PopupMenu_EmptybarHEID
.space 4

dlabel PopupMenu_TitleIconHEID
.space 4

dlabel PopupMenu_TimesHEID
.space 4

dlabel PopupMenu_PartnerLevelHEID
.space 4

dlabel PopupMenu_CursorHEID
.space 4

dlabel PopupMenu_UpArrowHEID
.space 4

dlabel PopupMenu_DownArrowHEID
.space 4

dlabel PopupMenu_EntryIconHEID
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

dlabel PopupMenu_StarPieceCounterPosX
.space 2

dlabel PopupMenu_StarPieceCounterPosY
.space 2

dlabel D_8010D68C
.space 2

dlabel PopupNotBattle
.space 1

dlabel PopupMenu_MaxDisplayableEntryCount
.space 1

dlabel D_8010D690
.space 1

dlabel D_8010D691
.space 1

dlabel D_8010D692
.space 1

dlabel D_8010D693
.space 1

dlabel gPopupWorker
.space 4

dlabel PopupNotDipping
.space 1

dlabel PopupDipMode
.space 1

dlabel PopupMenu_WasStatusBarIgnoringChanges
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

dlabel gPartnerStatus
.space 0x360

dlabel gSpinHistoryPosY
.space 0x18

dlabel gSpinHistoryPosX
.space 0x18

dlabel gSpinHistoryPosZ
.space 0x18

dlabel gStatusBar
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

#endif
