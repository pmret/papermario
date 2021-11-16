.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80270048
.double 0.3

.section .text

glabel pause_partners_update
/* 13FAE4 8024C7A4 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13FAE8 8024C7A8 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13FAEC 8024C7AC 00021840 */  sll       $v1, $v0, 1
/* 13FAF0 8024C7B0 00621821 */  addu      $v1, $v1, $v0
/* 13FAF4 8024C7B4 00031100 */  sll       $v0, $v1, 4
/* 13FAF8 8024C7B8 00431023 */  subu      $v0, $v0, $v1
/* 13FAFC 8024C7BC 3C038027 */  lui       $v1, %hi(D_802706B0)
/* 13FB00 8024C7C0 8C6306B0 */  lw        $v1, %lo(D_802706B0)($v1)
/* 13FB04 8024C7C4 000210C0 */  sll       $v0, $v0, 3
/* 13FB08 8024C7C8 14600002 */  bnez      $v1, .L8024C7D4
/* 13FB0C 8024C7CC 0043001A */   div      $zero, $v0, $v1
/* 13FB10 8024C7D0 0007000D */  break     7
.L8024C7D4:
/* 13FB14 8024C7D4 2401FFFF */   addiu    $at, $zero, -1
/* 13FB18 8024C7D8 14610004 */  bne       $v1, $at, .L8024C7EC
/* 13FB1C 8024C7DC 3C018000 */   lui      $at, 0x8000
/* 13FB20 8024C7E0 14410002 */  bne       $v0, $at, .L8024C7EC
/* 13FB24 8024C7E4 00000000 */   nop
/* 13FB28 8024C7E8 0006000D */  break     6
.L8024C7EC:
/* 13FB2C 8024C7EC 00001012 */   mflo     $v0
/* 13FB30 8024C7F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 13FB34 8024C7F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 13FB38 8024C7F8 3C118027 */  lui       $s1, %hi(D_802706A8)
/* 13FB3C 8024C7FC 263106A8 */  addiu     $s1, $s1, %lo(D_802706A8)
/* 13FB40 8024C800 AFBF0020 */  sw        $ra, 0x20($sp)
/* 13FB44 8024C804 AFB3001C */  sw        $s3, 0x1c($sp)
/* 13FB48 8024C808 AFB20018 */  sw        $s2, 0x18($sp)
/* 13FB4C 8024C80C AFB00010 */  sw        $s0, 0x10($sp)
/* 13FB50 8024C810 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 13FB54 8024C814 C6220000 */  lwc1      $f2, ($s1)
/* 13FB58 8024C818 44820000 */  mtc1      $v0, $f0
/* 13FB5C 8024C81C 00000000 */  nop
/* 13FB60 8024C820 46800020 */  cvt.s.w   $f0, $f0
/* 13FB64 8024C824 46020501 */  sub.s     $f20, $f0, $f2
/* 13FB68 8024C828 4600A10D */  trunc.w.s $f4, $f20
/* 13FB6C 8024C82C 44042000 */  mfc1      $a0, $f4
/* 13FB70 8024C830 00000000 */  nop
/* 13FB74 8024C834 04810002 */  bgez      $a0, .L8024C840
/* 13FB78 8024C838 0080802D */   daddu    $s0, $a0, $zero
/* 13FB7C 8024C83C 00108023 */  negu      $s0, $s0
.L8024C840:
/* 13FB80 8024C840 0C00A52C */  jal       sign
/* 13FB84 8024C844 00000000 */   nop
/* 13FB88 8024C848 0040182D */  daddu     $v1, $v0, $zero
/* 13FB8C 8024C84C 2A020010 */  slti      $v0, $s0, 0x10
/* 13FB90 8024C850 14400008 */  bnez      $v0, .L8024C874
/* 13FB94 8024C854 00000000 */   nop
/* 13FB98 8024C858 3C018027 */  lui       $at, %hi(D_80270048)
/* 13FB9C 8024C85C D4220048 */  ldc1      $f2, %lo(D_80270048)($at)
/* 13FBA0 8024C860 4600A021 */  cvt.d.s   $f0, $f20
/* 13FBA4 8024C864 46220002 */  mul.d     $f0, $f0, $f2
/* 13FBA8 8024C868 00000000 */  nop
/* 13FBAC 8024C86C 0809322D */  j         .L8024C8B4
/* 13FBB0 8024C870 462000A0 */   cvt.s.d  $f2, $f0
.L8024C874:
/* 13FBB4 8024C874 3C028025 */  lui       $v0, %hi(D_8024F87C)
/* 13FBB8 8024C878 00501021 */  addu      $v0, $v0, $s0
/* 13FBBC 8024C87C 9042F87C */  lbu       $v0, %lo(D_8024F87C)($v0)
/* 13FBC0 8024C880 C6200000 */  lwc1      $f0, ($s1)
/* 13FBC4 8024C884 00620018 */  mult      $v1, $v0
/* 13FBC8 8024C888 4600010D */  trunc.w.s $f4, $f0
/* 13FBCC 8024C88C 44022000 */  mfc1      $v0, $f4
/* 13FBD0 8024C890 00000000 */  nop
/* 13FBD4 8024C894 44820000 */  mtc1      $v0, $f0
/* 13FBD8 8024C898 00000000 */  nop
/* 13FBDC 8024C89C 46800020 */  cvt.s.w   $f0, $f0
/* 13FBE0 8024C8A0 E6200000 */  swc1      $f0, ($s1)
/* 13FBE4 8024C8A4 00003812 */  mflo      $a3
/* 13FBE8 8024C8A8 44871000 */  mtc1      $a3, $f2
/* 13FBEC 8024C8AC 00000000 */  nop
/* 13FBF0 8024C8B0 468010A0 */  cvt.s.w   $f2, $f2
.L8024C8B4:
/* 13FBF4 8024C8B4 3C028027 */  lui       $v0, %hi(D_802706A8)
/* 13FBF8 8024C8B8 244206A8 */  addiu     $v0, $v0, %lo(D_802706A8)
/* 13FBFC 8024C8BC C4400000 */  lwc1      $f0, ($v0)
/* 13FC00 8024C8C0 46020000 */  add.s     $f0, $f0, $f2
/* 13FC04 8024C8C4 3C038027 */  lui       $v1, %hi(D_802706B0)
/* 13FC08 8024C8C8 8C6306B0 */  lw        $v1, %lo(D_802706B0)($v1)
/* 13FC0C 8024C8CC 0000882D */  daddu     $s1, $zero, $zero
/* 13FC10 8024C8D0 18600024 */  blez      $v1, .L8024C964
/* 13FC14 8024C8D4 E4400000 */   swc1     $f0, ($v0)
/* 13FC18 8024C8D8 3C138027 */  lui       $s3, %hi(D_80270660)
/* 13FC1C 8024C8DC 26730660 */  addiu     $s3, $s3, %lo(D_80270660)
/* 13FC20 8024C8E0 3C128025 */  lui       $s2, %hi(D_8024F630)
/* 13FC24 8024C8E4 2652F630 */  addiu     $s2, $s2, %lo(D_8024F630)
/* 13FC28 8024C8E8 3C108027 */  lui       $s0, %hi(D_80270680)
/* 13FC2C 8024C8EC 26100680 */  addiu     $s0, $s0, %lo(D_80270680)
.L8024C8F0:
/* 13FC30 8024C8F0 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13FC34 8024C8F4 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13FC38 8024C8F8 1622000A */  bne       $s1, $v0, .L8024C924
/* 13FC3C 8024C8FC 00000000 */   nop
/* 13FC40 8024C900 8E030000 */  lw        $v1, ($s0)
/* 13FC44 8024C904 3C063F80 */  lui       $a2, 0x3f80
/* 13FC48 8024C908 00031080 */  sll       $v0, $v1, 2
/* 13FC4C 8024C90C 00531021 */  addu      $v0, $v0, $s3
/* 13FC50 8024C910 00031900 */  sll       $v1, $v1, 4
/* 13FC54 8024C914 00721821 */  addu      $v1, $v1, $s2
/* 13FC58 8024C918 8C440000 */  lw        $a0, ($v0)
/* 13FC5C 8024C91C 08093251 */  j         .L8024C944
/* 13FC60 8024C920 8C650004 */   lw       $a1, 4($v1)
.L8024C924:
/* 13FC64 8024C924 8E030000 */  lw        $v1, ($s0)
/* 13FC68 8024C928 3C063F80 */  lui       $a2, 0x3f80
/* 13FC6C 8024C92C 00031080 */  sll       $v0, $v1, 2
/* 13FC70 8024C930 00531021 */  addu      $v0, $v0, $s3
/* 13FC74 8024C934 00031900 */  sll       $v1, $v1, 4
/* 13FC78 8024C938 00721821 */  addu      $v1, $v1, $s2
/* 13FC7C 8024C93C 8C440000 */  lw        $a0, ($v0)
/* 13FC80 8024C940 8C650000 */  lw        $a1, ($v1)
.L8024C944:
/* 13FC84 8024C944 0C0B78AB */  jal       spr_update_sprite
/* 13FC88 8024C948 26100004 */   addiu    $s0, $s0, 4
/* 13FC8C 8024C94C 3C028027 */  lui       $v0, %hi(D_802706B0)
/* 13FC90 8024C950 8C4206B0 */  lw        $v0, %lo(D_802706B0)($v0)
/* 13FC94 8024C954 26310001 */  addiu     $s1, $s1, 1
/* 13FC98 8024C958 0222102A */  slt       $v0, $s1, $v0
/* 13FC9C 8024C95C 1440FFE4 */  bnez      $v0, .L8024C8F0
/* 13FCA0 8024C960 00000000 */   nop
.L8024C964:
/* 13FCA4 8024C964 8FBF0020 */  lw        $ra, 0x20($sp)
/* 13FCA8 8024C968 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13FCAC 8024C96C 8FB20018 */  lw        $s2, 0x18($sp)
/* 13FCB0 8024C970 8FB10014 */  lw        $s1, 0x14($sp)
/* 13FCB4 8024C974 8FB00010 */  lw        $s0, 0x10($sp)
/* 13FCB8 8024C978 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 13FCBC 8024C97C 03E00008 */  jr        $ra
/* 13FCC0 8024C980 27BD0030 */   addiu    $sp, $sp, 0x30
