.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245744_A2F984
/* A2F984 80245744 3C06FC12 */  lui       $a2, 0xfc12
/* A2F988 80245748 34C61624 */  ori       $a2, $a2, 0x1624
/* A2F98C 8024574C 3C05FF2F */  lui       $a1, 0xff2f
/* A2F990 80245750 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* A2F994 80245754 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* A2F998 80245758 8C820000 */  lw        $v0, ($a0)
/* A2F99C 8024575C 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A2F9A0 80245760 0040182D */  daddu     $v1, $v0, $zero
/* A2F9A4 80245764 24420008 */  addiu     $v0, $v0, 8
/* A2F9A8 80245768 AC820000 */  sw        $v0, ($a0)
/* A2F9AC 8024576C AC660000 */  sw        $a2, ($v1)
/* A2F9B0 80245770 AC650004 */  sw        $a1, 4($v1)
/* A2F9B4 80245774 24430008 */  addiu     $v1, $v0, 8
/* A2F9B8 80245778 AC830000 */  sw        $v1, ($a0)
/* A2F9BC 8024577C 3C048025 */  lui       $a0, %hi(D_8024DCD3)
/* A2F9C0 80245780 9084DCD3 */  lbu       $a0, %lo(D_8024DCD3)($a0)
/* A2F9C4 80245784 3C03FA00 */  lui       $v1, 0xfa00
/* A2F9C8 80245788 AC430000 */  sw        $v1, ($v0)
/* A2F9CC 8024578C 03E00008 */  jr        $ra
/* A2F9D0 80245790 AC440004 */   sw       $a0, 4($v0)
