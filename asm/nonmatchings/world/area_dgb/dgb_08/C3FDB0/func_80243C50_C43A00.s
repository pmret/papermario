.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243C50_C43A00
/* C43A00 80243C50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C43A04 80243C54 AFBF0010 */  sw        $ra, 0x10($sp)
/* C43A08 80243C58 8C820148 */  lw        $v0, 0x148($a0)
/* C43A0C 80243C5C 0C00EABB */  jal       get_npc_unsafe
/* C43A10 80243C60 84440008 */   lh       $a0, 8($v0)
/* C43A14 80243C64 0040202D */  daddu     $a0, $v0, $zero
/* C43A18 80243C68 2405032F */  addiu     $a1, $zero, 0x32f
/* C43A1C 80243C6C 0C012530 */  jal       func_800494C0
/* C43A20 80243C70 0000302D */   daddu    $a2, $zero, $zero
/* C43A24 80243C74 8FBF0010 */  lw        $ra, 0x10($sp)
/* C43A28 80243C78 24020002 */  addiu     $v0, $zero, 2
/* C43A2C 80243C7C 03E00008 */  jr        $ra
/* C43A30 80243C80 27BD0018 */   addiu    $sp, $sp, 0x18
/* C43A34 80243C84 00000000 */  nop
/* C43A38 80243C88 00000000 */  nop
/* C43A3C 80243C8C 00000000 */  nop
