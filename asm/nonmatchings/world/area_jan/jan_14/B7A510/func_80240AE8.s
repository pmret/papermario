.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE8
/* B7AB38 80240AE8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B7AB3C 80240AEC AFB40040 */  sw        $s4, 0x40($sp)
/* B7AB40 80240AF0 0080A02D */  daddu     $s4, $a0, $zero
/* B7AB44 80240AF4 AFBF0044 */  sw        $ra, 0x44($sp)
/* B7AB48 80240AF8 AFB3003C */  sw        $s3, 0x3c($sp)
/* B7AB4C 80240AFC AFB20038 */  sw        $s2, 0x38($sp)
/* B7AB50 80240B00 AFB10034 */  sw        $s1, 0x34($sp)
/* B7AB54 80240B04 AFB00030 */  sw        $s0, 0x30($sp)
/* B7AB58 80240B08 8E920148 */  lw        $s2, 0x148($s4)
/* B7AB5C 80240B0C 00A0882D */  daddu     $s1, $a1, $zero
/* B7AB60 80240B10 86440008 */  lh        $a0, 8($s2)
/* B7AB64 80240B14 0C00EABB */  jal       get_npc_unsafe
/* B7AB68 80240B18 00C0982D */   daddu    $s3, $a2, $zero
/* B7AB6C 80240B1C 8E230014 */  lw        $v1, 0x14($s1)
/* B7AB70 80240B20 0460002D */  bltz      $v1, .L80240BD8
/* B7AB74 80240B24 0040802D */   daddu    $s0, $v0, $zero
/* B7AB78 80240B28 0260202D */  daddu     $a0, $s3, $zero
/* B7AB7C 80240B2C AFA00010 */  sw        $zero, 0x10($sp)
/* B7AB80 80240B30 8E260024 */  lw        $a2, 0x24($s1)
/* B7AB84 80240B34 8E270028 */  lw        $a3, 0x28($s1)
/* B7AB88 80240B38 0C01242D */  jal       func_800490B4
/* B7AB8C 80240B3C 0240282D */   daddu    $a1, $s2, $zero
/* B7AB90 80240B40 10400025 */  beqz      $v0, .L80240BD8
/* B7AB94 80240B44 0000202D */   daddu    $a0, $zero, $zero
/* B7AB98 80240B48 0200282D */  daddu     $a1, $s0, $zero
/* B7AB9C 80240B4C 0000302D */  daddu     $a2, $zero, $zero
/* B7ABA0 80240B50 860300A8 */  lh        $v1, 0xa8($s0)
/* B7ABA4 80240B54 3C013F80 */  lui       $at, 0x3f80
/* B7ABA8 80240B58 44810000 */  mtc1      $at, $f0
/* B7ABAC 80240B5C 3C014000 */  lui       $at, 0x4000
/* B7ABB0 80240B60 44811000 */  mtc1      $at, $f2
/* B7ABB4 80240B64 3C01C1A0 */  lui       $at, 0xc1a0
/* B7ABB8 80240B68 44812000 */  mtc1      $at, $f4
/* B7ABBC 80240B6C 2402000F */  addiu     $v0, $zero, 0xf
/* B7ABC0 80240B70 AFA2001C */  sw        $v0, 0x1c($sp)
/* B7ABC4 80240B74 44833000 */  mtc1      $v1, $f6
/* B7ABC8 80240B78 00000000 */  nop       
/* B7ABCC 80240B7C 468031A0 */  cvt.s.w   $f6, $f6
/* B7ABD0 80240B80 44073000 */  mfc1      $a3, $f6
/* B7ABD4 80240B84 27A20028 */  addiu     $v0, $sp, 0x28
/* B7ABD8 80240B88 AFA20020 */  sw        $v0, 0x20($sp)
/* B7ABDC 80240B8C E7A00010 */  swc1      $f0, 0x10($sp)
/* B7ABE0 80240B90 E7A20014 */  swc1      $f2, 0x14($sp)
/* B7ABE4 80240B94 0C01BFA4 */  jal       fx_emote
/* B7ABE8 80240B98 E7A40018 */   swc1     $f4, 0x18($sp)
/* B7ABEC 80240B9C 0200202D */  daddu     $a0, $s0, $zero
/* B7ABF0 80240BA0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B7ABF4 80240BA4 0C012530 */  jal       func_800494C0
/* B7ABF8 80240BA8 3C060020 */   lui      $a2, 0x20
/* B7ABFC 80240BAC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B7AC00 80240BB0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B7AC04 80240BB4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B7AC08 80240BB8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B7AC0C 80240BBC 8C460028 */  lw        $a2, 0x28($v0)
/* B7AC10 80240BC0 0C00A720 */  jal       atan2
/* B7AC14 80240BC4 8C470030 */   lw       $a3, 0x30($v0)
/* B7AC18 80240BC8 2402000C */  addiu     $v0, $zero, 0xc
/* B7AC1C 80240BCC E600000C */  swc1      $f0, 0xc($s0)
/* B7AC20 80240BD0 0809031B */  j         .L80240C6C
/* B7AC24 80240BD4 AE820070 */   sw       $v0, 0x70($s4)
.L80240BD8:
/* B7AC28 80240BD8 8602008C */  lh        $v0, 0x8c($s0)
/* B7AC2C 80240BDC 14400023 */  bnez      $v0, .L80240C6C
/* B7AC30 80240BE0 00000000 */   nop      
/* B7AC34 80240BE4 9602008E */  lhu       $v0, 0x8e($s0)
/* B7AC38 80240BE8 2442FFFF */  addiu     $v0, $v0, -1
/* B7AC3C 80240BEC A602008E */  sh        $v0, 0x8e($s0)
/* B7AC40 80240BF0 00021400 */  sll       $v0, $v0, 0x10
/* B7AC44 80240BF4 1C40001D */  bgtz      $v0, .L80240C6C
/* B7AC48 80240BF8 00000000 */   nop      
/* B7AC4C 80240BFC 8E820074 */  lw        $v0, 0x74($s4)
/* B7AC50 80240C00 2442FFFF */  addiu     $v0, $v0, -1
/* B7AC54 80240C04 18400018 */  blez      $v0, .L80240C68
/* B7AC58 80240C08 AE820074 */   sw       $v0, 0x74($s4)
/* B7AC5C 80240C0C C600000C */  lwc1      $f0, 0xc($s0)
/* B7AC60 80240C10 3C014334 */  lui       $at, 0x4334
/* B7AC64 80240C14 44816000 */  mtc1      $at, $f12
/* B7AC68 80240C18 0C00A6C9 */  jal       clamp_angle
/* B7AC6C 80240C1C 460C0300 */   add.s    $f12, $f0, $f12
/* B7AC70 80240C20 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B7AC74 80240C24 0C00A67F */  jal       rand_int
/* B7AC78 80240C28 E600000C */   swc1     $f0, 0xc($s0)
/* B7AC7C 80240C2C 3C032E8B */  lui       $v1, 0x2e8b
/* B7AC80 80240C30 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B7AC84 80240C34 00430018 */  mult      $v0, $v1
/* B7AC88 80240C38 00021FC3 */  sra       $v1, $v0, 0x1f
/* B7AC8C 80240C3C 00004010 */  mfhi      $t0
/* B7AC90 80240C40 00082043 */  sra       $a0, $t0, 1
/* B7AC94 80240C44 00832023 */  subu      $a0, $a0, $v1
/* B7AC98 80240C48 00041840 */  sll       $v1, $a0, 1
/* B7AC9C 80240C4C 00641821 */  addu      $v1, $v1, $a0
/* B7ACA0 80240C50 00031880 */  sll       $v1, $v1, 2
/* B7ACA4 80240C54 00641823 */  subu      $v1, $v1, $a0
/* B7ACA8 80240C58 00431023 */  subu      $v0, $v0, $v1
/* B7ACAC 80240C5C 24420005 */  addiu     $v0, $v0, 5
/* B7ACB0 80240C60 0809031B */  j         .L80240C6C
/* B7ACB4 80240C64 A602008E */   sh       $v0, 0x8e($s0)
.L80240C68:
/* B7ACB8 80240C68 AE800070 */  sw        $zero, 0x70($s4)
.L80240C6C:
/* B7ACBC 80240C6C 8FBF0044 */  lw        $ra, 0x44($sp)
/* B7ACC0 80240C70 8FB40040 */  lw        $s4, 0x40($sp)
/* B7ACC4 80240C74 8FB3003C */  lw        $s3, 0x3c($sp)
/* B7ACC8 80240C78 8FB20038 */  lw        $s2, 0x38($sp)
/* B7ACCC 80240C7C 8FB10034 */  lw        $s1, 0x34($sp)
/* B7ACD0 80240C80 8FB00030 */  lw        $s0, 0x30($sp)
/* B7ACD4 80240C84 03E00008 */  jr        $ra
/* B7ACD8 80240C88 27BD0048 */   addiu    $sp, $sp, 0x48
