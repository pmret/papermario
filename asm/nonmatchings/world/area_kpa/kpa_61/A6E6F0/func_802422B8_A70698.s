.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422B8_A70698
/* A70698 802422B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7069C 802422BC 3C05FE36 */  lui       $a1, 0xfe36
/* A706A0 802422C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A706A4 802422C4 8C820148 */  lw        $v0, 0x148($a0)
/* A706A8 802422C8 3C06800B */  lui       $a2, 0x800b
/* A706AC 802422CC 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A706B0 802422D0 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A706B4 802422D4 00C23026 */  xor       $a2, $a2, $v0
/* A706B8 802422D8 0C0B2026 */  jal       set_variable
/* A706BC 802422DC 2CC60001 */   sltiu    $a2, $a2, 1
/* A706C0 802422E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A706C4 802422E4 24020002 */  addiu     $v0, $zero, 2
/* A706C8 802422E8 03E00008 */  jr        $ra
/* A706CC 802422EC 27BD0018 */   addiu    $sp, $sp, 0x18
