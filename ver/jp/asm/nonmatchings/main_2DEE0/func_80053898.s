.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053898
/* 2EC98 80053898 30A20070 */  andi      $v0, $a1, 0x70
/* 2EC9C 8005389C 00021082 */  srl       $v0, $v0, 2
/* 2ECA0 800538A0 00822021 */  addu      $a0, $a0, $v0
/* 2ECA4 800538A4 8C8212EC */  lw        $v0, 0x12ec($a0)
/* 2ECA8 800538A8 00063080 */  sll       $a2, $a2, 2
/* 2ECAC 800538AC 00C23021 */  addu      $a2, $a2, $v0
/* 2ECB0 800538B0 8CC60000 */  lw        $a2, ($a2)
/* 2ECB4 800538B4 8CC4002C */  lw        $a0, 0x2c($a2)
/* 2ECB8 800538B8 90820000 */  lbu       $v0, ($a0)
/* 2ECBC 800538BC 30A50003 */  andi      $a1, $a1, 3
/* 2ECC0 800538C0 00A2102B */  sltu      $v0, $a1, $v0
/* 2ECC4 800538C4 10400009 */  beqz      $v0, .L800538EC
/* 2ECC8 800538C8 00000000 */   nop
/* 2ECCC 800538CC 00051080 */  sll       $v0, $a1, 2
/* 2ECD0 800538D0 00821021 */  addu      $v0, $a0, $v0
/* 2ECD4 800538D4 94430004 */  lhu       $v1, 4($v0)
/* 2ECD8 800538D8 00641821 */  addu      $v1, $v1, $a0
/* 2ECDC 800538DC ACE30000 */  sw        $v1, ($a3)
/* 2ECE0 800538E0 94420006 */  lhu       $v0, 6($v0)
/* 2ECE4 800538E4 08014E3F */  j         .L800538FC
/* 2ECE8 800538E8 00441021 */   addu     $v0, $v0, $a0
.L800538EC:
/* 2ECEC 800538EC 3C028008 */  lui       $v0, %hi(D_8007851C)
/* 2ECF0 800538F0 2442851C */  addiu     $v0, $v0, %lo(D_8007851C)
/* 2ECF4 800538F4 ACE20000 */  sw        $v0, ($a3)
/* 2ECF8 800538F8 24420004 */  addiu     $v0, $v0, 4
.L800538FC:
/* 2ECFC 800538FC ACE20004 */  sw        $v0, 4($a3)
/* 2ED00 80053900 03E00008 */  jr        $ra
/* 2ED04 80053904 00C0102D */   daddu    $v0, $a2, $zero
