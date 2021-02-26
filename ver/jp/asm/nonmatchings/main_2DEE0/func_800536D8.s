.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800536D8
/* 2EAD8 800536D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2EADC 800536DC AFB00010 */  sw        $s0, 0x10($sp)
/* 2EAE0 800536E0 0080802D */  daddu     $s0, $a0, $zero
/* 2EAE4 800536E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2EAE8 800536E8 9602000A */  lhu       $v0, 0xa($s0)
/* 2EAEC 800536EC 2442FFFF */  addiu     $v0, $v0, -1
/* 2EAF0 800536F0 A602000A */  sh        $v0, 0xa($s0)
/* 2EAF4 800536F4 00021400 */  sll       $v0, $v0, 0x10
/* 2EAF8 800536F8 10400006 */  beqz      $v0, .L80053714
/* 2EAFC 800536FC 00000000 */   nop
/* 2EB00 80053700 8E020000 */  lw        $v0, ($s0)
/* 2EB04 80053704 8E030004 */  lw        $v1, 4($s0)
/* 2EB08 80053708 00431021 */  addu      $v0, $v0, $v1
/* 2EB0C 8005370C 08014DCE */  j         .L80053738
/* 2EB10 80053710 AE020000 */   sw       $v0, ($s0)
.L80053714:
/* 2EB14 80053714 86020008 */  lh        $v0, 8($s0)
/* 2EB18 80053718 8E03000C */  lw        $v1, 0xc($s0)
/* 2EB1C 8005371C 00021400 */  sll       $v0, $v0, 0x10
/* 2EB20 80053720 10600005 */  beqz      $v1, .L80053738
/* 2EB24 80053724 AE020000 */   sw       $v0, ($s0)
/* 2EB28 80053728 0060F809 */  jalr      $v1
/* 2EB2C 8005372C 00000000 */   nop
/* 2EB30 80053730 AE000004 */  sw        $zero, 4($s0)
/* 2EB34 80053734 AE00000C */  sw        $zero, 0xc($s0)
.L80053738:
/* 2EB38 80053738 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2EB3C 8005373C 8FB00010 */  lw        $s0, 0x10($sp)
/* 2EB40 80053740 03E00008 */  jr        $ra
/* 2EB44 80053744 27BD0018 */   addiu    $sp, $sp, 0x18
