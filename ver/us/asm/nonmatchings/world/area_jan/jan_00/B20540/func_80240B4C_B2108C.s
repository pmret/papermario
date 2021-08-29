.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B4C_B2108C
/* B2108C 80240B4C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B21090 80240B50 AFB20018 */  sw        $s2, 0x18($sp)
/* B21094 80240B54 0080902D */  daddu     $s2, $a0, $zero
/* B21098 80240B58 AFBF0028 */  sw        $ra, 0x28($sp)
/* B2109C 80240B5C AFB50024 */  sw        $s5, 0x24($sp)
/* B210A0 80240B60 AFB40020 */  sw        $s4, 0x20($sp)
/* B210A4 80240B64 AFB3001C */  sw        $s3, 0x1c($sp)
/* B210A8 80240B68 AFB10014 */  sw        $s1, 0x14($sp)
/* B210AC 80240B6C AFB00010 */  sw        $s0, 0x10($sp)
/* B210B0 80240B70 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* B210B4 80240B74 F7B80040 */  sdc1      $f24, 0x40($sp)
/* B210B8 80240B78 F7B60038 */  sdc1      $f22, 0x38($sp)
/* B210BC 80240B7C F7B40030 */  sdc1      $f20, 0x30($sp)
/* B210C0 80240B80 8E50000C */  lw        $s0, 0xc($s2)
/* B210C4 80240B84 4480A000 */  mtc1      $zero, $f20
/* B210C8 80240B88 8E050000 */  lw        $a1, ($s0)
/* B210CC 80240B8C 26100004 */  addiu     $s0, $s0, 4
/* B210D0 80240B90 4600A686 */  mov.s     $f26, $f20
/* B210D4 80240B94 0C0B1EAF */  jal       get_variable
/* B210D8 80240B98 4600A606 */   mov.s    $f24, $f20
/* B210DC 80240B9C 8E130000 */  lw        $s3, ($s0)
/* B210E0 80240BA0 26100004 */  addiu     $s0, $s0, 4
/* B210E4 80240BA4 0000202D */  daddu     $a0, $zero, $zero
/* B210E8 80240BA8 8E140000 */  lw        $s4, ($s0)
/* B210EC 80240BAC 8E150004 */  lw        $s5, 4($s0)
/* B210F0 80240BB0 0C00EAD2 */  jal       get_npc_safe
/* B210F4 80240BB4 0040882D */   daddu    $s1, $v0, $zero
/* B210F8 80240BB8 0040802D */  daddu     $s0, $v0, $zero
/* B210FC 80240BBC 24020001 */  addiu     $v0, $zero, 1
/* B21100 80240BC0 1222000F */  beq       $s1, $v0, .L80240C00
/* B21104 80240BC4 2A220002 */   slti     $v0, $s1, 2
/* B21108 80240BC8 10400005 */  beqz      $v0, .L80240BE0
/* B2110C 80240BCC 24020002 */   addiu    $v0, $zero, 2
/* B21110 80240BD0 12200007 */  beqz      $s1, .L80240BF0
/* B21114 80240BD4 00000000 */   nop
/* B21118 80240BD8 08090308 */  j         .L80240C20
/* B2111C 80240BDC 00000000 */   nop
.L80240BE0:
/* B21120 80240BE0 1222000B */  beq       $s1, $v0, .L80240C10
/* B21124 80240BE4 00000000 */   nop
/* B21128 80240BE8 08090308 */  j         .L80240C20
/* B2112C 80240BEC 00000000 */   nop
.L80240BF0:
/* B21130 80240BF0 3C014302 */  lui       $at, 0x4302
/* B21134 80240BF4 4481B000 */  mtc1      $at, $f22
/* B21138 80240BF8 0809030B */  j         .L80240C2C
/* B2113C 80240BFC 2A220004 */   slti     $v0, $s1, 4
.L80240C00:
/* B21140 80240C00 3C014320 */  lui       $at, 0x4320
/* B21144 80240C04 4481B000 */  mtc1      $at, $f22
/* B21148 80240C08 0809030B */  j         .L80240C2C
/* B2114C 80240C0C 2A220004 */   slti     $v0, $s1, 4
.L80240C10:
/* B21150 80240C10 3C0142C8 */  lui       $at, 0x42c8
/* B21154 80240C14 4481B000 */  mtc1      $at, $f22
/* B21158 80240C18 0809030B */  j         .L80240C2C
/* B2115C 80240C1C 2A220004 */   slti     $v0, $s1, 4
.L80240C20:
/* B21160 80240C20 3C0142A0 */  lui       $at, 0x42a0
/* B21164 80240C24 4481B000 */  mtc1      $at, $f22
/* B21168 80240C28 2A220004 */  slti      $v0, $s1, 4
.L80240C2C:
/* B2116C 80240C2C 10400019 */  beqz      $v0, .L80240C94
/* B21170 80240C30 0240202D */   daddu    $a0, $s2, $zero
/* B21174 80240C34 C614000C */  lwc1      $f20, 0xc($s0)
/* B21178 80240C38 4600A507 */  neg.s     $f20, $f20
/* B2117C 80240C3C 0C00A8BB */  jal       sin_deg
/* B21180 80240C40 4600A306 */   mov.s    $f12, $f20
/* B21184 80240C44 46160002 */  mul.s     $f0, $f0, $f22
/* B21188 80240C48 00000000 */  nop
/* B2118C 80240C4C C6020038 */  lwc1      $f2, 0x38($s0)
/* B21190 80240C50 3C0141F0 */  lui       $at, 0x41f0
/* B21194 80240C54 44812000 */  mtc1      $at, $f4
/* B21198 80240C58 00000000 */  nop
/* B2119C 80240C5C 46041080 */  add.s     $f2, $f2, $f4
/* B211A0 80240C60 46001680 */  add.s     $f26, $f2, $f0
/* B211A4 80240C64 0C00A8D4 */  jal       cos_deg
/* B211A8 80240C68 4600A306 */   mov.s    $f12, $f20
/* B211AC 80240C6C 46160002 */  mul.s     $f0, $f0, $f22
/* B211B0 80240C70 00000000 */  nop
/* B211B4 80240C74 C604003C */  lwc1      $f4, 0x3c($s0)
/* B211B8 80240C78 3C014248 */  lui       $at, 0x4248
/* B211BC 80240C7C 44811000 */  mtc1      $at, $f2
/* B211C0 80240C80 00000000 */  nop
/* B211C4 80240C84 46022500 */  add.s     $f20, $f4, $f2
/* B211C8 80240C88 C6020040 */  lwc1      $f2, 0x40($s0)
/* B211CC 80240C8C 46001600 */  add.s     $f24, $f2, $f0
/* B211D0 80240C90 0240202D */  daddu     $a0, $s2, $zero
.L80240C94:
/* B211D4 80240C94 4406D000 */  mfc1      $a2, $f26
/* B211D8 80240C98 0C0B2190 */  jal       evt_set_float_variable
/* B211DC 80240C9C 0260282D */   daddu    $a1, $s3, $zero
/* B211E0 80240CA0 0240202D */  daddu     $a0, $s2, $zero
/* B211E4 80240CA4 4406A000 */  mfc1      $a2, $f20
/* B211E8 80240CA8 0C0B2190 */  jal       evt_set_float_variable
/* B211EC 80240CAC 0280282D */   daddu    $a1, $s4, $zero
/* B211F0 80240CB0 0240202D */  daddu     $a0, $s2, $zero
/* B211F4 80240CB4 4406C000 */  mfc1      $a2, $f24
/* B211F8 80240CB8 0C0B2190 */  jal       evt_set_float_variable
/* B211FC 80240CBC 02A0282D */   daddu    $a1, $s5, $zero
/* B21200 80240CC0 8FBF0028 */  lw        $ra, 0x28($sp)
/* B21204 80240CC4 8FB50024 */  lw        $s5, 0x24($sp)
/* B21208 80240CC8 8FB40020 */  lw        $s4, 0x20($sp)
/* B2120C 80240CCC 8FB3001C */  lw        $s3, 0x1c($sp)
/* B21210 80240CD0 8FB20018 */  lw        $s2, 0x18($sp)
/* B21214 80240CD4 8FB10014 */  lw        $s1, 0x14($sp)
/* B21218 80240CD8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2121C 80240CDC D7BA0048 */  ldc1      $f26, 0x48($sp)
/* B21220 80240CE0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* B21224 80240CE4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* B21228 80240CE8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* B2122C 80240CEC 24020002 */  addiu     $v0, $zero, 2
/* B21230 80240CF0 03E00008 */  jr        $ra
/* B21234 80240CF4 27BD0050 */   addiu    $sp, $sp, 0x50
