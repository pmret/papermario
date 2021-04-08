.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A808
/* 15C08 8003A808 0000182D */  daddu     $v1, $zero, $zero
/* 15C0C 8003A80C 3C06800A */  lui       $a2, %hi(D_8009E9A0)
/* 15C10 8003A810 8CC6E9A0 */  lw        $a2, %lo(D_8009E9A0)($a2)
.L8003A814:
/* 15C14 8003A814 8CC50000 */  lw        $a1, ($a2)
/* 15C18 8003A818 50A00008 */  beql      $a1, $zero, .L8003A83C
/* 15C1C 8003A81C 24630001 */   addiu    $v1, $v1, 1
/* 15C20 8003A820 8CA20000 */  lw        $v0, ($a1)
/* 15C24 8003A824 50400005 */  beql      $v0, $zero, .L8003A83C
/* 15C28 8003A828 24630001 */   addiu    $v1, $v1, 1
/* 15C2C 8003A82C 80A200A4 */  lb        $v0, 0xa4($a1)
/* 15C30 8003A830 50440006 */  beql      $v0, $a0, .L8003A84C
/* 15C34 8003A834 28630040 */   slti     $v1, $v1, 0x40
/* 15C38 8003A838 24630001 */  addiu     $v1, $v1, 1
.L8003A83C:
/* 15C3C 8003A83C 28620040 */  slti      $v0, $v1, 0x40
/* 15C40 8003A840 1440FFF4 */  bnez      $v0, .L8003A814
/* 15C44 8003A844 24C60004 */   addiu    $a2, $a2, 4
/* 15C48 8003A848 28630040 */  slti      $v1, $v1, 0x40
.L8003A84C:
/* 15C4C 8003A84C 10600002 */  beqz      $v1, .L8003A858
/* 15C50 8003A850 0000102D */   daddu    $v0, $zero, $zero
/* 15C54 8003A854 00A0102D */  daddu     $v0, $a1, $zero
.L8003A858:
/* 15C58 8003A858 03E00008 */  jr        $ra
/* 15C5C 8003A85C 00000000 */   nop
