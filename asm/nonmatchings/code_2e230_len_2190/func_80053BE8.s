.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053BE8
/* 2EFE8 80053BE8 30A20070 */  andi      $v0, $a1, 0x70
/* 2EFEC 80053BEC 00021082 */  srl       $v0, $v0, 2
/* 2EFF0 80053BF0 00822021 */  addu      $a0, $a0, $v0
/* 2EFF4 80053BF4 8C8212EC */  lw        $v0, 0x12ec($a0)
/* 2EFF8 80053BF8 00063080 */  sll       $a2, $a2, 2
/* 2EFFC 80053BFC 00C23021 */  addu      $a2, $a2, $v0
/* 2F000 80053C00 8CC60000 */  lw        $a2, ($a2)
/* 2F004 80053C04 8CC4002C */  lw        $a0, 0x2c($a2)
/* 2F008 80053C08 90820000 */  lbu       $v0, ($a0)
/* 2F00C 80053C0C 30A50003 */  andi      $a1, $a1, 3
/* 2F010 80053C10 00A2102B */  sltu      $v0, $a1, $v0
/* 2F014 80053C14 10400009 */  beqz      $v0, .L80053C3C
/* 2F018 80053C18 00000000 */   nop      
/* 2F01C 80053C1C 00051080 */  sll       $v0, $a1, 2
/* 2F020 80053C20 00821021 */  addu      $v0, $a0, $v0
/* 2F024 80053C24 94430004 */  lhu       $v1, 4($v0)
/* 2F028 80053C28 00641821 */  addu      $v1, $v1, $a0
/* 2F02C 80053C2C ACE30000 */  sw        $v1, ($a3)
/* 2F030 80053C30 94420006 */  lhu       $v0, 6($v0)
/* 2F034 80053C34 08014F13 */  j         .L80053C4C
/* 2F038 80053C38 00441021 */   addu     $v0, $v0, $a0
.L80053C3C:
/* 2F03C 80053C3C 3C028008 */  lui       $v0, %hi(D_8007854C)
/* 2F040 80053C40 2442854C */  addiu     $v0, $v0, %lo(D_8007854C)
/* 2F044 80053C44 ACE20000 */  sw        $v0, ($a3)
/* 2F048 80053C48 24420004 */  addiu     $v0, $v0, 4
.L80053C4C:
/* 2F04C 80053C4C ACE20004 */  sw        $v0, 4($a3)
/* 2F050 80053C50 03E00008 */  jr        $ra
/* 2F054 80053C54 00C0102D */   daddu    $v0, $a2, $zero
