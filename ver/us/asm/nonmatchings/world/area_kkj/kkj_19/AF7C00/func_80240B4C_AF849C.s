.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B4C_AF849C
/* AF849C 80240B4C 54A00001 */  bnel      $a1, $zero, .L80240B54
/* AF84A0 80240B50 AC800074 */   sw       $zero, 0x74($a0)
.L80240B54:
/* AF84A4 80240B54 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AF84A8 80240B58 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AF84AC 80240B5C 8C420010 */  lw        $v0, 0x10($v0)
/* AF84B0 80240B60 30428000 */  andi      $v0, $v0, 0x8000
/* AF84B4 80240B64 14400006 */  bnez      $v0, .L80240B80
/* AF84B8 80240B68 24020002 */   addiu    $v0, $zero, 2
/* AF84BC 80240B6C 8C830074 */  lw        $v1, 0x74($a0)
/* AF84C0 80240B70 0000102D */  daddu     $v0, $zero, $zero
/* AF84C4 80240B74 24630001 */  addiu     $v1, $v1, 1
/* AF84C8 80240B78 03E00008 */  jr        $ra
/* AF84CC 80240B7C AC830074 */   sw       $v1, 0x74($a0)
.L80240B80:
/* AF84D0 80240B80 8C830074 */  lw        $v1, 0x74($a0)
/* AF84D4 80240B84 03E00008 */  jr        $ra
/* AF84D8 80240B88 AC830084 */   sw       $v1, 0x84($a0)
