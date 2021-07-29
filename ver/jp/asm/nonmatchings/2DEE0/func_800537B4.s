.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800537B4
/* 2EBB4 800537B4 3C020001 */  lui       $v0, 1
/* 2EBB8 800537B8 344285A6 */  ori       $v0, $v0, 0x85a6
/* 2EBBC 800537BC 24A3FF06 */  addiu     $v1, $a1, -0xfa
/* 2EBC0 800537C0 0043102B */  sltu      $v0, $v0, $v1
/* 2EBC4 800537C4 14400021 */  bnez      $v0, .L8005384C
/* 2EBC8 800537C8 0080382D */   daddu    $a3, $a0, $zero
/* 2EBCC 800537CC 3C03B65C */  lui       $v1, 0xb65c
/* 2EBD0 800537D0 34636D59 */  ori       $v1, $v1, 0x6d59
/* 2EBD4 800537D4 00051140 */  sll       $v0, $a1, 5
/* 2EBD8 800537D8 00451023 */  subu      $v0, $v0, $a1
/* 2EBDC 800537DC 00021080 */  sll       $v0, $v0, 2
/* 2EBE0 800537E0 00451021 */  addu      $v0, $v0, $a1
/* 2EBE4 800537E4 000210C0 */  sll       $v0, $v0, 3
/* 2EBE8 800537E8 00430018 */  mult      $v0, $v1
/* 2EBEC 800537EC 00001810 */  mfhi      $v1
/* 2EBF0 800537F0 00622021 */  addu      $a0, $v1, $v0
/* 2EBF4 800537F4 00042303 */  sra       $a0, $a0, 0xc
/* 2EBF8 800537F8 000217C3 */  sra       $v0, $v0, 0x1f
/* 2EBFC 800537FC 00822023 */  subu      $a0, $a0, $v0
/* 2EC00 80053800 8CE20010 */  lw        $v0, 0x10($a3)
/* 2EC04 80053804 00061C00 */  sll       $v1, $a2, 0x10
/* 2EC08 80053808 00621823 */  subu      $v1, $v1, $v0
/* 2EC0C 8005380C 00041400 */  sll       $v0, $a0, 0x10
/* 2EC10 80053810 00021403 */  sra       $v0, $v0, 0x10
/* 2EC14 80053814 14400002 */  bnez      $v0, .L80053820
/* 2EC18 80053818 0062001A */   div      $zero, $v1, $v0
/* 2EC1C 8005381C 0007000D */  break     7
.L80053820:
/* 2EC20 80053820 2401FFFF */   addiu    $at, $zero, -1
/* 2EC24 80053824 14410004 */  bne       $v0, $at, .L80053838
/* 2EC28 80053828 3C018000 */   lui      $at, 0x8000
/* 2EC2C 8005382C 14610002 */  bne       $v1, $at, .L80053838
/* 2EC30 80053830 00000000 */   nop
/* 2EC34 80053834 0006000D */  break     6
.L80053838:
/* 2EC38 80053838 00001812 */   mflo     $v1
/* 2EC3C 8005383C A4E60018 */  sh        $a2, 0x18($a3)
/* 2EC40 80053840 A4E4001A */  sh        $a0, 0x1a($a3)
/* 2EC44 80053844 03E00008 */  jr        $ra
/* 2EC48 80053848 ACE30014 */   sw       $v1, 0x14($a3)
.L8005384C:
/* 2EC4C 8005384C A4E0001A */  sh        $zero, 0x1a($a3)
/* 2EC50 80053850 03E00008 */  jr        $ra
/* 2EC54 80053854 ACE00014 */   sw       $zero, 0x14($a3)
