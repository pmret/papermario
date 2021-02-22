.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B694
/* 26A94 8004B694 30A500FF */  andi      $a1, $a1, 0xff
/* 26A98 8004B698 240200F0 */  addiu     $v0, $zero, 0xf0
/* 26A9C 8004B69C 10A20017 */  beq       $a1, $v0, .L8004B6FC
/* 26AA0 8004B6A0 28A20008 */   slti     $v0, $a1, 8
/* 26AA4 8004B6A4 10400013 */  beqz      $v0, .L8004B6F4
/* 26AA8 8004B6A8 240200FF */   addiu    $v0, $zero, 0xff
/* 26AAC 8004B6AC 9082008C */  lbu       $v0, 0x8c($a0)
/* 26AB0 8004B6B0 1045000C */  beq       $v0, $a1, .L8004B6E4
/* 26AB4 8004B6B4 24020006 */   addiu    $v0, $zero, 6
/* 26AB8 8004B6B8 8C830000 */  lw        $v1, ($a0)
/* 26ABC 8004B6BC A085008C */  sb        $a1, 0x8c($a0)
/* 26AC0 8004B6C0 A0620044 */  sb        $v0, 0x44($v1)
/* 26AC4 8004B6C4 8C830000 */  lw        $v1, ($a0)
/* 26AC8 8004B6C8 24020001 */  addiu     $v0, $zero, 1
/* 26ACC 8004B6CC A0620045 */  sb        $v0, 0x45($v1)
/* 26AD0 8004B6D0 00051080 */  sll       $v0, $a1, 2
/* 26AD4 8004B6D4 00821021 */  addu      $v0, $a0, $v0
/* 26AD8 8004B6D8 8C420064 */  lw        $v0, 0x64($v0)
/* 26ADC 8004B6DC 3C018008 */  lui       $at, %hi(D_8007F1C8)
/* 26AE0 8004B6E0 AC22F1C8 */  sw        $v0, %lo(D_8007F1C8)($at)
.L8004B6E4:
/* 26AE4 8004B6E4 00851021 */  addu      $v0, $a0, $a1
/* 26AE8 8004B6E8 90420084 */  lbu       $v0, 0x84($v0)
/* 26AEC 8004B6EC 08012DBF */  j         .L8004B6FC
/* 26AF0 8004B6F0 A082008D */   sb       $v0, 0x8d($a0)
.L8004B6F4:
/* 26AF4 8004B6F4 A082008C */  sb        $v0, 0x8c($a0)
/* 26AF8 8004B6F8 A080008D */  sb        $zero, 0x8d($a0)
.L8004B6FC:
/* 26AFC 8004B6FC 03E00008 */  jr        $ra
/* 26B00 8004B700 9082008C */   lbu      $v0, 0x8c($a0)
