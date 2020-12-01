.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024564C_A2F88C
/* A2F88C 8024564C 3C06FC12 */  lui       $a2, 0xfc12
/* A2F890 80245650 34C61624 */  ori       $a2, $a2, 0x1624
/* A2F894 80245654 3C05FF2F */  lui       $a1, 0xff2f
/* A2F898 80245658 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* A2F89C 8024565C 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* A2F8A0 80245660 8C820000 */  lw        $v0, ($a0)
/* A2F8A4 80245664 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A2F8A8 80245668 0040182D */  daddu     $v1, $v0, $zero
/* A2F8AC 8024566C 24420008 */  addiu     $v0, $v0, 8
/* A2F8B0 80245670 AC820000 */  sw        $v0, ($a0)
/* A2F8B4 80245674 AC660000 */  sw        $a2, ($v1)
/* A2F8B8 80245678 AC650004 */  sw        $a1, 4($v1)
/* A2F8BC 8024567C 24430008 */  addiu     $v1, $v0, 8
/* A2F8C0 80245680 AC830000 */  sw        $v1, ($a0)
/* A2F8C4 80245684 3C04802E */  lui       $a0, %hi(D_802D9D73)
/* A2F8C8 80245688 90849D73 */  lbu       $a0, %lo(D_802D9D73)($a0)
/* A2F8CC 8024568C 3C03FA00 */  lui       $v1, 0xfa00
/* A2F8D0 80245690 AC430000 */  sw        $v1, ($v0)
/* A2F8D4 80245694 03E00008 */  jr        $ra
/* A2F8D8 80245698 AC440004 */   sw       $a0, 4($v0)
