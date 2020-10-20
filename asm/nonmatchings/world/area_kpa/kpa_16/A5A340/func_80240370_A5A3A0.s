.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240370_A5A3A0
/* A5A3A0 80240370 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A5A3A4 80240374 AFBF0010 */  sw        $ra, 0x10($sp)
/* A5A3A8 80240378 8C82000C */  lw        $v0, 0xc($a0)
/* A5A3AC 8024037C 3C068016 */  lui       $a2, 0x8016
/* A5A3B0 80240380 84C6A552 */  lh        $a2, -0x5aae($a2)
/* A5A3B4 80240384 0C0B2026 */  jal       set_variable
/* A5A3B8 80240388 8C450000 */   lw       $a1, ($v0)
/* A5A3BC 8024038C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A5A3C0 80240390 24020002 */  addiu     $v0, $zero, 2
/* A5A3C4 80240394 03E00008 */  jr        $ra
/* A5A3C8 80240398 27BD0018 */   addiu    $sp, $sp, 0x18
/* A5A3CC 8024039C 00000000 */  nop       
