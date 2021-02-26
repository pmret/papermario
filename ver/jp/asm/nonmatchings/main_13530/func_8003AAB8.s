.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AAB8
/* 15EB8 8003AAB8 8C850020 */  lw        $a1, 0x20($a0)
/* 15EBC 8003AABC 80A30001 */  lb        $v1, 1($a1)
/* 15EC0 8003AAC0 C4800038 */  lwc1      $f0, 0x38($a0)
/* 15EC4 8003AAC4 00031080 */  sll       $v0, $v1, 2
/* 15EC8 8003AAC8 00A21021 */  addu      $v0, $a1, $v0
/* 15ECC 8003AACC E4400004 */  swc1      $f0, 4($v0)
/* 15ED0 8003AAD0 C480003C */  lwc1      $f0, 0x3c($a0)
/* 15ED4 8003AAD4 E4400054 */  swc1      $f0, 0x54($v0)
/* 15ED8 8003AAD8 C4800040 */  lwc1      $f0, 0x40($a0)
/* 15EDC 8003AADC 24630001 */  addiu     $v1, $v1, 1
/* 15EE0 8003AAE0 E44000A4 */  swc1      $f0, 0xa4($v0)
/* 15EE4 8003AAE4 28620014 */  slti      $v0, $v1, 0x14
/* 15EE8 8003AAE8 50400001 */  beql      $v0, $zero, .L8003AAF0
/* 15EEC 8003AAEC 0000182D */   daddu    $v1, $zero, $zero
.L8003AAF0:
/* 15EF0 8003AAF0 03E00008 */  jr        $ra
/* 15EF4 8003AAF4 A0A30001 */   sb       $v1, 1($a1)
