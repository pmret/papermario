.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218250_52B8F0
/* 52B8F0 80218250 27BDFD80 */  addiu     $sp, $sp, -0x280
/* 52B8F4 80218254 27A30018 */  addiu     $v1, $sp, 0x18
/* 52B8F8 80218258 3C028023 */  lui       $v0, %hi(D_8022FC30_5432D0)
/* 52B8FC 8021825C 2442FC30 */  addiu     $v0, $v0, %lo(D_8022FC30_5432D0)
/* 52B900 80218260 24440250 */  addiu     $a0, $v0, 0x250
/* 52B904 80218264 AFBF0278 */  sw        $ra, 0x278($sp)
/* 52B908 80218268 AFB10274 */  sw        $s1, 0x274($sp)
/* 52B90C 8021826C AFB00270 */  sw        $s0, 0x270($sp)
.L80218270:
/* 52B910 80218270 8C480000 */  lw        $t0, ($v0)
/* 52B914 80218274 8C490004 */  lw        $t1, 4($v0)
/* 52B918 80218278 8C4A0008 */  lw        $t2, 8($v0)
/* 52B91C 8021827C 8C4B000C */  lw        $t3, 0xc($v0)
/* 52B920 80218280 AC680000 */  sw        $t0, ($v1)
/* 52B924 80218284 AC690004 */  sw        $t1, 4($v1)
/* 52B928 80218288 AC6A0008 */  sw        $t2, 8($v1)
/* 52B92C 8021828C AC6B000C */  sw        $t3, 0xc($v1)
/* 52B930 80218290 24420010 */  addiu     $v0, $v0, 0x10
/* 52B934 80218294 1444FFF6 */  bne       $v0, $a0, .L80218270
/* 52B938 80218298 24630010 */   addiu    $v1, $v1, 0x10
/* 52B93C 8021829C 8C480000 */  lw        $t0, ($v0)
/* 52B940 802182A0 8C490004 */  lw        $t1, 4($v0)
/* 52B944 802182A4 AC680000 */  sw        $t0, ($v1)
/* 52B948 802182A8 AC690004 */  sw        $t1, 4($v1)
/* 52B94C 802182AC 0000882D */  daddu     $s1, $zero, $zero
/* 52B950 802182B0 27B00018 */  addiu     $s0, $sp, 0x18
.L802182B4:
/* 52B954 802182B4 C6000010 */  lwc1      $f0, 0x10($s0)
/* 52B958 802182B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 52B95C 802182BC 8E020014 */  lw        $v0, 0x14($s0)
/* 52B960 802182C0 AFA20014 */  sw        $v0, 0x14($sp)
/* 52B964 802182C4 8E040000 */  lw        $a0, ($s0)
/* 52B968 802182C8 8E050004 */  lw        $a1, 4($s0)
/* 52B96C 802182CC 8E060008 */  lw        $a2, 8($s0)
/* 52B970 802182D0 8E07000C */  lw        $a3, 0xc($s0)
/* 52B974 802182D4 0C01C994 */  jal       fx_ice_shard
/* 52B978 802182D8 26310001 */   addiu    $s1, $s1, 1
/* 52B97C 802182DC 8C43000C */  lw        $v1, 0xc($v0)
/* 52B980 802182E0 C6000018 */  lwc1      $f0, 0x18($s0)
/* 52B984 802182E4 E460004C */  swc1      $f0, 0x4c($v1)
/* 52B988 802182E8 8C43000C */  lw        $v1, 0xc($v0)
/* 52B98C 802182EC C600001C */  lwc1      $f0, 0x1c($s0)
/* 52B990 802182F0 E4600050 */  swc1      $f0, 0x50($v1)
/* 52B994 802182F4 8C43000C */  lw        $v1, 0xc($v0)
/* 52B998 802182F8 C6000020 */  lwc1      $f0, 0x20($s0)
/* 52B99C 802182FC E4600054 */  swc1      $f0, 0x54($v1)
/* 52B9A0 80218300 8C42000C */  lw        $v0, 0xc($v0)
/* 52B9A4 80218304 C6000024 */  lwc1      $f0, 0x24($s0)
/* 52B9A8 80218308 E4400058 */  swc1      $f0, 0x58($v0)
/* 52B9AC 8021830C 2A22000F */  slti      $v0, $s1, 0xf
/* 52B9B0 80218310 1440FFE8 */  bnez      $v0, .L802182B4
/* 52B9B4 80218314 26100028 */   addiu    $s0, $s0, 0x28
/* 52B9B8 80218318 8FBF0278 */  lw        $ra, 0x278($sp)
/* 52B9BC 8021831C 8FB10274 */  lw        $s1, 0x274($sp)
/* 52B9C0 80218320 8FB00270 */  lw        $s0, 0x270($sp)
/* 52B9C4 80218324 24020002 */  addiu     $v0, $zero, 2
/* 52B9C8 80218328 03E00008 */  jr        $ra
/* 52B9CC 8021832C 27BD0280 */   addiu    $sp, $sp, 0x280
