.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DC4
/* A4A384 80241DC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4A388 80241DC8 3C05FE36 */  lui       $a1, 0xfe36
/* A4A38C 80241DCC AFBF0010 */  sw        $ra, 0x10($sp)
/* A4A390 80241DD0 8C820148 */  lw        $v0, 0x148($a0)
/* A4A394 80241DD4 3C06800B */  lui       $a2, 0x800b
/* A4A398 80241DD8 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A4A39C 80241DDC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4A3A0 80241DE0 00C23026 */  xor       $a2, $a2, $v0
/* A4A3A4 80241DE4 0C0B2026 */  jal       set_variable
/* A4A3A8 80241DE8 2CC60001 */   sltiu    $a2, $a2, 1
/* A4A3AC 80241DEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A4A3B0 80241DF0 24020002 */  addiu     $v0, $zero, 2
/* A4A3B4 80241DF4 03E00008 */  jr        $ra
/* A4A3B8 80241DF8 27BD0018 */   addiu    $sp, $sp, 0x18
