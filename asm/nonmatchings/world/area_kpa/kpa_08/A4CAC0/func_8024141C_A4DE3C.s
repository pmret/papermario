.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024141C_A4DE3C
/* A4DE3C 8024141C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4DE40 80241420 3C05FE36 */  lui       $a1, 0xfe36
/* A4DE44 80241424 AFBF0010 */  sw        $ra, 0x10($sp)
/* A4DE48 80241428 8C820148 */  lw        $v0, 0x148($a0)
/* A4DE4C 8024142C 3C06800B */  lui       $a2, 0x800b
/* A4DE50 80241430 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A4DE54 80241434 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A4DE58 80241438 00C23026 */  xor       $a2, $a2, $v0
/* A4DE5C 8024143C 0C0B2026 */  jal       set_variable
/* A4DE60 80241440 2CC60001 */   sltiu    $a2, $a2, 1
/* A4DE64 80241444 8FBF0010 */  lw        $ra, 0x10($sp)
/* A4DE68 80241448 24020002 */  addiu     $v0, $zero, 2
/* A4DE6C 8024144C 03E00008 */  jr        $ra
/* A4DE70 80241450 27BD0018 */   addiu    $sp, $sp, 0x18
