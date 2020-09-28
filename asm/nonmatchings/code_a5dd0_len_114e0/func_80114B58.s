.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80114B58
/* AB258 80114B58 3C028015 */  lui       $v0, 0x8015
/* AB25C 80114B5C 8C423368 */  lw        $v0, 0x3368($v0)
/* AB260 80114B60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AB264 80114B64 AFB1002C */  sw        $s1, 0x2c($sp)
/* AB268 80114B68 0080882D */  daddu     $s1, $a0, $zero
/* AB26C 80114B6C AFB20030 */  sw        $s2, 0x30($sp)
/* AB270 80114B70 00A0902D */  daddu     $s2, $a1, $zero
/* AB274 80114B74 AFB70044 */  sw        $s7, 0x44($sp)
/* AB278 80114B78 00C0B82D */  daddu     $s7, $a2, $zero
/* AB27C 80114B7C AFB40038 */  sw        $s4, 0x38($sp)
/* AB280 80114B80 AFBF0048 */  sw        $ra, 0x48($sp)
/* AB284 80114B84 AFB60040 */  sw        $s6, 0x40($sp)
/* AB288 80114B88 AFB5003C */  sw        $s5, 0x3c($sp)
/* AB28C 80114B8C AFB30034 */  sw        $s3, 0x34($sp)
/* AB290 80114B90 AFB00028 */  sw        $s0, 0x28($sp)
/* AB294 80114B94 AE420034 */  sw        $v0, 0x34($s2)
/* AB298 80114B98 8FB30060 */  lw        $s3, 0x60($sp)
/* AB29C 80114B9C 8FB50064 */  lw        $s5, 0x64($sp)
/* AB2A0 80114BA0 8FB60068 */  lw        $s6, 0x68($sp)
/* AB2A4 80114BA4 12600004 */  beqz      $s3, .L80114BB8
/* AB2A8 80114BA8 00E0A02D */   daddu    $s4, $a3, $zero
/* AB2AC 80114BAC 00541021 */  addu      $v0, $v0, $s4
/* AB2B0 80114BB0 080452EF */  j         .L80114BBC
/* AB2B4 80114BB4 AE420038 */   sw       $v0, 0x38($s2)
.L80114BB8:
/* AB2B8 80114BB8 AE400038 */  sw        $zero, 0x38($s2)
.L80114BBC:
/* AB2BC 80114BBC 0220202D */  daddu     $a0, $s1, $zero
/* AB2C0 80114BC0 3C108015 */  lui       $s0, 0x8015
/* AB2C4 80114BC4 26103368 */  addiu     $s0, $s0, 0x3368
/* AB2C8 80114BC8 02342821 */  addu      $a1, $s1, $s4
/* AB2CC 80114BCC 8E060000 */  lw        $a2, ($s0)
/* AB2D0 80114BD0 0C00A5CF */  jal       dma_copy
/* AB2D4 80114BD4 00B32821 */   addu     $a1, $a1, $s3
/* AB2D8 80114BD8 02931021 */  addu      $v0, $s4, $s3
/* AB2DC 80114BDC 8E030000 */  lw        $v1, ($s0)
/* AB2E0 80114BE0 02228821 */  addu      $s1, $s1, $v0
/* AB2E4 80114BE4 00621021 */  addu      $v0, $v1, $v0
/* AB2E8 80114BE8 12A00013 */  beqz      $s5, .L80114C38
/* AB2EC 80114BEC AE020000 */   sw       $v0, ($s0)
/* AB2F0 80114BF0 12C00004 */  beqz      $s6, .L80114C04
/* AB2F4 80114BF4 AE42003C */   sw       $v0, 0x3c($s2)
/* AB2F8 80114BF8 00551021 */  addu      $v0, $v0, $s5
/* AB2FC 80114BFC 08045302 */  j         .L80114C08
/* AB300 80114C00 AE420040 */   sw       $v0, 0x40($s2)
.L80114C04:
/* AB304 80114C04 AE400040 */  sw        $zero, 0x40($s2)
.L80114C08:
/* AB308 80114C08 0220202D */  daddu     $a0, $s1, $zero
/* AB30C 80114C0C 3C108015 */  lui       $s0, 0x8015
/* AB310 80114C10 26103368 */  addiu     $s0, $s0, 0x3368
/* AB314 80114C14 00952821 */  addu      $a1, $a0, $s5
/* AB318 80114C18 8E060000 */  lw        $a2, ($s0)
/* AB31C 80114C1C 0C00A5CF */  jal       dma_copy
/* AB320 80114C20 00B62821 */   addu     $a1, $a1, $s6
/* AB324 80114C24 8E020000 */  lw        $v0, ($s0)
/* AB328 80114C28 02B61821 */  addu      $v1, $s5, $s6
/* AB32C 80114C2C 00431021 */  addu      $v0, $v0, $v1
/* AB330 80114C30 08045310 */  j         .L80114C40
/* AB334 80114C34 AE020000 */   sw       $v0, ($s0)
.L80114C38:
/* AB338 80114C38 AE400040 */  sw        $zero, 0x40($s2)
/* AB33C 80114C3C AE40003C */  sw        $zero, 0x3c($s2)
.L80114C40:
/* AB340 80114C40 26450004 */  addiu     $a1, $s2, 4
/* AB344 80114C44 02E0202D */  daddu     $a0, $s7, $zero
/* AB348 80114C48 02E51025 */  or        $v0, $s7, $a1
/* AB34C 80114C4C 3C038015 */  lui       $v1, 0x8015
/* AB350 80114C50 8C633368 */  lw        $v1, 0x3368($v1)
/* AB354 80114C54 30420003 */  andi      $v0, $v0, 3
/* AB358 80114C58 10400017 */  beqz      $v0, .L80114CB8
/* AB35C 80114C5C AE430000 */   sw       $v1, ($s2)
/* AB360 80114C60 26E20030 */  addiu     $v0, $s7, 0x30
.L80114C64:
/* AB364 80114C64 88880000 */  lwl       $t0, ($a0)
/* AB368 80114C68 98880003 */  lwr       $t0, 3($a0)
/* AB36C 80114C6C 88890004 */  lwl       $t1, 4($a0)
/* AB370 80114C70 98890007 */  lwr       $t1, 7($a0)
/* AB374 80114C74 888A0008 */  lwl       $t2, 8($a0)
/* AB378 80114C78 988A000B */  lwr       $t2, 0xb($a0)
/* AB37C 80114C7C 888B000C */  lwl       $t3, 0xc($a0)
/* AB380 80114C80 988B000F */  lwr       $t3, 0xf($a0)
/* AB384 80114C84 A8A80000 */  swl       $t0, ($a1)
/* AB388 80114C88 B8A80003 */  swr       $t0, 3($a1)
/* AB38C 80114C8C A8A90004 */  swl       $t1, 4($a1)
/* AB390 80114C90 B8A90007 */  swr       $t1, 7($a1)
/* AB394 80114C94 A8AA0008 */  swl       $t2, 8($a1)
/* AB398 80114C98 B8AA000B */  swr       $t2, 0xb($a1)
/* AB39C 80114C9C A8AB000C */  swl       $t3, 0xc($a1)
/* AB3A0 80114CA0 B8AB000F */  swr       $t3, 0xf($a1)
/* AB3A4 80114CA4 24840010 */  addiu     $a0, $a0, 0x10
/* AB3A8 80114CA8 1482FFEE */  bne       $a0, $v0, .L80114C64
/* AB3AC 80114CAC 24A50010 */   addiu    $a1, $a1, 0x10
/* AB3B0 80114CB0 0804533A */  j         .L80114CE8
/* AB3B4 80114CB4 00000000 */   nop      
.L80114CB8:
/* AB3B8 80114CB8 26E20030 */  addiu     $v0, $s7, 0x30
.L80114CBC:
/* AB3BC 80114CBC 8C880000 */  lw        $t0, ($a0)
/* AB3C0 80114CC0 8C890004 */  lw        $t1, 4($a0)
/* AB3C4 80114CC4 8C8A0008 */  lw        $t2, 8($a0)
/* AB3C8 80114CC8 8C8B000C */  lw        $t3, 0xc($a0)
/* AB3CC 80114CCC ACA80000 */  sw        $t0, ($a1)
/* AB3D0 80114CD0 ACA90004 */  sw        $t1, 4($a1)
/* AB3D4 80114CD4 ACAA0008 */  sw        $t2, 8($a1)
/* AB3D8 80114CD8 ACAB000C */  sw        $t3, 0xc($a1)
/* AB3DC 80114CDC 24840010 */  addiu     $a0, $a0, 0x10
/* AB3E0 80114CE0 1482FFF6 */  bne       $a0, $v0, .L80114CBC
/* AB3E4 80114CE4 24A50010 */   addiu    $a1, $a1, 0x10
.L80114CE8:
/* AB3E8 80114CE8 8E42003C */  lw        $v0, 0x3c($s2)
/* AB3EC 80114CEC 02E0202D */  daddu     $a0, $s7, $zero
/* AB3F0 80114CF0 AFA20010 */  sw        $v0, 0x10($sp)
/* AB3F4 80114CF4 8E420040 */  lw        $v0, 0x40($s2)
/* AB3F8 80114CF8 3C108015 */  lui       $s0, 0x8015
/* AB3FC 80114CFC 26103368 */  addiu     $s0, $s0, 0x3368
/* AB400 80114D00 AFA00018 */  sw        $zero, 0x18($sp)
/* AB404 80114D04 AFA0001C */  sw        $zero, 0x1c($sp)
/* AB408 80114D08 AFA00020 */  sw        $zero, 0x20($sp)
/* AB40C 80114D0C AFA00024 */  sw        $zero, 0x24($sp)
/* AB410 80114D10 AFA20014 */  sw        $v0, 0x14($sp)
/* AB414 80114D14 8E460034 */  lw        $a2, 0x34($s2)
/* AB418 80114D18 8E470038 */  lw        $a3, 0x38($s2)
/* AB41C 80114D1C 0C04603A */  jal       func_801180E8
/* AB420 80114D20 0200282D */   daddu    $a1, $s0, $zero
/* AB424 80114D24 8E020000 */  lw        $v0, ($s0)
/* AB428 80114D28 0040182D */  daddu     $v1, $v0, $zero
/* AB42C 80114D2C 24420008 */  addiu     $v0, $v0, 8
/* AB430 80114D30 AE020000 */  sw        $v0, ($s0)
/* AB434 80114D34 3C02DF00 */  lui       $v0, 0xdf00
/* AB438 80114D38 AC620000 */  sw        $v0, ($v1)
/* AB43C 80114D3C AC600004 */  sw        $zero, 4($v1)
/* AB440 80114D40 8FBF0048 */  lw        $ra, 0x48($sp)
/* AB444 80114D44 8FB70044 */  lw        $s7, 0x44($sp)
/* AB448 80114D48 8FB60040 */  lw        $s6, 0x40($sp)
/* AB44C 80114D4C 8FB5003C */  lw        $s5, 0x3c($sp)
/* AB450 80114D50 8FB40038 */  lw        $s4, 0x38($sp)
/* AB454 80114D54 8FB30034 */  lw        $s3, 0x34($sp)
/* AB458 80114D58 8FB20030 */  lw        $s2, 0x30($sp)
/* AB45C 80114D5C 8FB1002C */  lw        $s1, 0x2c($sp)
/* AB460 80114D60 8FB00028 */  lw        $s0, 0x28($sp)
/* AB464 80114D64 03E00008 */  jr        $ra
/* AB468 80114D68 27BD0050 */   addiu    $sp, $sp, 0x50
