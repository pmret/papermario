.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243504_A96C44
/* A96C44 80243504 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A96C48 80243508 3C05FE36 */  lui       $a1, 0xfe36
/* A96C4C 8024350C AFBF0010 */  sw        $ra, 0x10($sp)
/* A96C50 80243510 8C820148 */  lw        $v0, 0x148($a0)
/* A96C54 80243514 3C06800B */  lui       $a2, 0x800b
/* A96C58 80243518 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A96C5C 8024351C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A96C60 80243520 00C23026 */  xor       $a2, $a2, $v0
/* A96C64 80243524 0C0B2026 */  jal       set_variable
/* A96C68 80243528 2CC60001 */   sltiu    $a2, $a2, 1
/* A96C6C 8024352C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A96C70 80243530 24020002 */  addiu     $v0, $zero, 2
/* A96C74 80243534 03E00008 */  jr        $ra
/* A96C78 80243538 27BD0018 */   addiu    $sp, $sp, 0x18
