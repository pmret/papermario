.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel play_movement_dust_effects
/* 192BD0 802642F0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 192BD4 802642F4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 192BD8 802642F8 4485B000 */  mtc1      $a1, $f22
/* 192BDC 802642FC F7B80030 */  sdc1      $f24, 0x30($sp)
/* 192BE0 80264300 4486C000 */  mtc1      $a2, $f24
/* 192BE4 80264304 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 192BE8 80264308 4487D000 */  mtc1      $a3, $f26
/* 192BEC 8026430C 24020002 */  addiu     $v0, $zero, 2
/* 192BF0 80264310 AFBF0018 */  sw        $ra, 0x18($sp)
/* 192BF4 80264314 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 192BF8 80264318 1482000C */  bne       $a0, $v0, .L8026434C
/* 192BFC 8026431C 24020001 */   addiu    $v0, $zero, 1
/* 192C00 80264320 44800000 */  mtc1      $zero, $f0
/* 192C04 80264324 00000000 */  nop
/* 192C08 80264328 4600C600 */  add.s     $f24, $f24, $f0
/* 192C0C 8026432C 3C018029 */  lui       $at, %hi(D_802938A4)
/* 192C10 80264330 C42038A4 */  lwc1      $f0, %lo(D_802938A4)($at)
/* 192C14 80264334 4406C000 */  mfc1      $a2, $f24
/* 192C18 80264338 0000202D */  daddu     $a0, $zero, $zero
/* 192C1C 8026433C 0C01BEB4 */  jal       fx_landing_dust
/* 192C20 80264340 E7A00010 */   swc1     $f0, 0x10($sp)
/* 192C24 80264344 08099110 */  j         .L80264440
/* 192C28 80264348 00000000 */   nop
.L8026434C:
/* 192C2C 8026434C 14820004 */  bne       $a0, $v0, .L80264360
/* 192C30 80264350 24020004 */   addiu    $v0, $zero, 4
/* 192C34 80264354 3C018029 */  lui       $at, %hi(D_802938A8)
/* 192C38 80264358 08099110 */  j         .L80264440
/* 192C3C 8026435C A42238A8 */   sh       $v0, %lo(D_802938A8)($at)
.L80264360:
/* 192C40 80264360 3C048029 */  lui       $a0, %hi(D_802938A8)
/* 192C44 80264364 248438A8 */  addiu     $a0, $a0, %lo(D_802938A8)
/* 192C48 80264368 94820000 */  lhu       $v0, ($a0)
/* 192C4C 8026436C 24430001 */  addiu     $v1, $v0, 1
/* 192C50 80264370 00021400 */  sll       $v0, $v0, 0x10
/* 192C54 80264374 00021403 */  sra       $v0, $v0, 0x10
/* 192C58 80264378 28420004 */  slti      $v0, $v0, 4
/* 192C5C 8026437C 14400030 */  bnez      $v0, .L80264440
/* 192C60 80264380 A4830000 */   sh       $v1, ($a0)
/* 192C64 80264384 A4800000 */  sh        $zero, ($a0)
/* 192C68 80264388 C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 192C6C 8026438C 0C00A6C9 */  jal       clamp_angle
/* 192C70 80264390 46006307 */   neg.s    $f12, $f12
/* 192C74 80264394 3C0140C9 */  lui       $at, 0x40c9
/* 192C78 80264398 34210FD0 */  ori       $at, $at, 0xfd0
/* 192C7C 8026439C 44811000 */  mtc1      $at, $f2
/* 192C80 802643A0 00000000 */  nop
/* 192C84 802643A4 46020502 */  mul.s     $f20, $f0, $f2
/* 192C88 802643A8 00000000 */  nop
/* 192C8C 802643AC 3C0143B4 */  lui       $at, 0x43b4
/* 192C90 802643B0 44810000 */  mtc1      $at, $f0
/* 192C94 802643B4 00000000 */  nop
/* 192C98 802643B8 4600A503 */  div.s     $f20, $f20, $f0
/* 192C9C 802643BC 0C00A85B */  jal       sin_rad
/* 192CA0 802643C0 4600A306 */   mov.s    $f12, $f20
/* 192CA4 802643C4 4600A306 */  mov.s     $f12, $f20
/* 192CA8 802643C8 0C00A874 */  jal       cos_rad
/* 192CAC 802643CC 46000506 */   mov.s    $f20, $f0
/* 192CB0 802643D0 3C0141C0 */  lui       $at, 0x41c0
/* 192CB4 802643D4 44812000 */  mtc1      $at, $f4
/* 192CB8 802643D8 00000000 */  nop
/* 192CBC 802643DC 4604A182 */  mul.s     $f6, $f20, $f4
/* 192CC0 802643E0 00000000 */  nop
/* 192CC4 802643E4 46040102 */  mul.s     $f4, $f0, $f4
/* 192CC8 802643E8 00000000 */  nop
/* 192CCC 802643EC 3C013E4C */  lui       $at, 0x3e4c
/* 192CD0 802643F0 3421CCCD */  ori       $at, $at, 0xcccd
/* 192CD4 802643F4 44811000 */  mtc1      $at, $f2
/* 192CD8 802643F8 00000000 */  nop
/* 192CDC 802643FC 46023182 */  mul.s     $f6, $f6, $f2
/* 192CE0 80264400 00000000 */  nop
/* 192CE4 80264404 46022102 */  mul.s     $f4, $f4, $f2
/* 192CE8 80264408 00000000 */  nop
/* 192CEC 8026440C 3C013FC0 */  lui       $at, 0x3fc0
/* 192CF0 80264410 44811000 */  mtc1      $at, $f2
/* 192CF4 80264414 00000000 */  nop
/* 192CF8 80264418 4602C600 */  add.s     $f24, $f24, $f2
/* 192CFC 8026441C 4606B580 */  add.s     $f22, $f22, $f6
/* 192D00 80264420 4604D680 */  add.s     $f26, $f26, $f4
/* 192D04 80264424 4406C000 */  mfc1      $a2, $f24
/* 192D08 80264428 4405B000 */  mfc1      $a1, $f22
/* 192D0C 8026442C 4407D000 */  mfc1      $a3, $f26
/* 192D10 80264430 0000202D */  daddu     $a0, $zero, $zero
/* 192D14 80264434 E7B40010 */  swc1      $f20, 0x10($sp)
/* 192D18 80264438 0C01BECC */  jal       fx_walking_dust
/* 192D1C 8026443C E7A00014 */   swc1     $f0, 0x14($sp)
.L80264440:
/* 192D20 80264440 8FBF0018 */  lw        $ra, 0x18($sp)
/* 192D24 80264444 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 192D28 80264448 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 192D2C 8026444C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 192D30 80264450 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 192D34 80264454 03E00008 */  jr        $ra
/* 192D38 80264458 27BD0040 */   addiu    $sp, $sp, 0x40
