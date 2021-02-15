.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E80_801700
/* 801700 80240E80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 801704 80240E84 AFB00010 */  sw        $s0, 0x10($sp)
/* 801708 80240E88 0080802D */  daddu     $s0, $a0, $zero
/* 80170C 80240E8C 3C05F5DE */  lui       $a1, 0xf5de
/* 801710 80240E90 AFBF0014 */  sw        $ra, 0x14($sp)
/* 801714 80240E94 0C0B1EAF */  jal       get_variable
/* 801718 80240E98 34A502DD */   ori      $a1, $a1, 0x2dd
/* 80171C 80240E9C 3C048025 */  lui       $a0, %hi(D_802485E8_808E68)
/* 801720 80240EA0 248485E8 */  addiu     $a0, $a0, %lo(D_802485E8_808E68)
/* 801724 80240EA4 00021840 */  sll       $v1, $v0, 1
/* 801728 80240EA8 00621821 */  addu      $v1, $v1, $v0
/* 80172C 80240EAC 00031880 */  sll       $v1, $v1, 2
/* 801730 80240EB0 00641821 */  addu      $v1, $v1, $a0
/* 801734 80240EB4 8C620000 */  lw        $v0, ($v1)
/* 801738 80240EB8 AE020084 */  sw        $v0, 0x84($s0)
/* 80173C 80240EBC 8C630004 */  lw        $v1, 4($v1)
/* 801740 80240EC0 AE030088 */  sw        $v1, 0x88($s0)
/* 801744 80240EC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 801748 80240EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 80174C 80240ECC 24020002 */  addiu     $v0, $zero, 2
/* 801750 80240ED0 03E00008 */  jr        $ra
/* 801754 80240ED4 27BD0018 */   addiu    $sp, $sp, 0x18
