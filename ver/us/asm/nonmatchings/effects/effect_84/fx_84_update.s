.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_84_update
/* 3A71F4 E00A8104 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A71F8 E00A8108 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A71FC E00A810C AFB3001C */  sw        $s3, 0x1c($sp)
/* 3A7200 E00A8110 AFB20018 */  sw        $s2, 0x18($sp)
/* 3A7204 E00A8114 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A7208 E00A8118 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A720C E00A811C 8C830000 */  lw        $v1, ($a0)
/* 3A7210 E00A8120 8C85000C */  lw        $a1, 0xc($a0)
/* 3A7214 E00A8124 30620010 */  andi      $v0, $v1, 0x10
/* 3A7218 E00A8128 10400005 */  beqz      $v0, .LE00A8140
/* 3A721C E00A812C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3A7220 E00A8130 00621024 */  and       $v0, $v1, $v0
/* 3A7224 E00A8134 AC820000 */  sw        $v0, ($a0)
/* 3A7228 E00A8138 2402001E */  addiu     $v0, $zero, 0x1e
/* 3A722C E00A813C ACA20004 */  sw        $v0, 4($a1)
.LE00A8140:
/* 3A7230 E00A8140 8CA30004 */  lw        $v1, 4($a1)
/* 3A7234 E00A8144 28620064 */  slti      $v0, $v1, 0x64
/* 3A7238 E00A8148 10400002 */  beqz      $v0, .LE00A8154
/* 3A723C E00A814C 2462FFFF */   addiu    $v0, $v1, -1
/* 3A7240 E00A8150 ACA20004 */  sw        $v0, 4($a1)
.LE00A8154:
/* 3A7244 E00A8154 8CA20008 */  lw        $v0, 8($a1)
/* 3A7248 E00A8158 8CA30004 */  lw        $v1, 4($a1)
/* 3A724C E00A815C 24420001 */  addiu     $v0, $v0, 1
/* 3A7250 E00A8160 04610005 */  bgez      $v1, .LE00A8178
/* 3A7254 E00A8164 ACA20008 */   sw       $v0, 8($a1)
/* 3A7258 E00A8168 0C080128 */  jal       shim_remove_effect
/* 3A725C E00A816C 00000000 */   nop
/* 3A7260 E00A8170 0802A0AE */  j         .LE00A82B8
/* 3A7264 E00A8174 00000000 */   nop
.LE00A8178:
/* 3A7268 E00A8178 28620010 */  slti      $v0, $v1, 0x10
/* 3A726C E00A817C 10400002 */  beqz      $v0, .LE00A8188
/* 3A7270 E00A8180 00031100 */   sll      $v0, $v1, 4
/* 3A7274 E00A8184 ACA20018 */  sw        $v0, 0x18($a1)
.LE00A8188:
/* 3A7278 E00A8188 0000882D */  daddu     $s1, $zero, $zero
/* 3A727C E00A818C 24120001 */  addiu     $s2, $zero, 1
/* 3A7280 E00A8190 3C13E00B */  lui       $s3, %hi(D_E00A8690)
/* 3A7284 E00A8194 26738690 */  addiu     $s3, $s3, %lo(D_E00A8690)
/* 3A7288 E00A8198 00A0802D */  daddu     $s0, $a1, $zero
.LE00A819C:
/* 3A728C E00A819C 8E02001C */  lw        $v0, 0x1c($s0)
/* 3A7290 E00A81A0 10400005 */  beqz      $v0, .LE00A81B8
/* 3A7294 E00A81A4 00000000 */   nop
/* 3A7298 E00A81A8 1052001E */  beq       $v0, $s2, .LE00A8224
/* 3A729C E00A81AC 00000000 */   nop
/* 3A72A0 E00A81B0 0802A0AA */  j         .LE00A82A8
/* 3A72A4 E00A81B4 26100004 */   addiu    $s0, $s0, 4
.LE00A81B8:
/* 3A72A8 E00A81B8 0C080138 */  jal       shim_rand_int
/* 3A72AC E00A81BC 2404000A */   addiu    $a0, $zero, 0xa
/* 3A72B0 E00A81C0 2403000A */  addiu     $v1, $zero, 0xa
/* 3A72B4 E00A81C4 54430038 */  bnel      $v0, $v1, .LE00A82A8
/* 3A72B8 E00A81C8 26100004 */   addiu    $s0, $s0, 4
/* 3A72BC E00A81CC 24040001 */  addiu     $a0, $zero, 1
/* 3A72C0 E00A81D0 0C080138 */  jal       shim_rand_int
/* 3A72C4 E00A81D4 AE12001C */   sw       $s2, 0x1c($s0)
/* 3A72C8 E00A81D8 24040032 */  addiu     $a0, $zero, 0x32
/* 3A72CC E00A81DC AE020044 */  sw        $v0, 0x44($s0)
/* 3A72D0 E00A81E0 0C080138 */  jal       shim_rand_int
/* 3A72D4 E00A81E4 AE00006C */   sw       $zero, 0x6c($s0)
/* 3A72D8 E00A81E8 3C01E00B */  lui       $at, %hi(D_E00A86A0)
/* 3A72DC E00A81EC D42086A0 */  ldc1      $f0, %lo(D_E00A86A0)($at)
/* 3A72E0 E00A81F0 44821000 */  mtc1      $v0, $f2
/* 3A72E4 E00A81F4 00000000 */  nop
/* 3A72E8 E00A81F8 468010A1 */  cvt.d.w   $f2, $f2
/* 3A72EC E00A81FC 46201082 */  mul.d     $f2, $f2, $f0
/* 3A72F0 E00A8200 00000000 */  nop
/* 3A72F4 E00A8204 3C013FE0 */  lui       $at, 0x3fe0
/* 3A72F8 E00A8208 44810800 */  mtc1      $at, $f1
/* 3A72FC E00A820C 44800000 */  mtc1      $zero, $f0
/* 3A7300 E00A8210 00000000 */  nop
/* 3A7304 E00A8214 46201080 */  add.d     $f2, $f2, $f0
/* 3A7308 E00A8218 462010A0 */  cvt.s.d   $f2, $f2
/* 3A730C E00A821C 0802A0A9 */  j         .LE00A82A4
/* 3A7310 E00A8220 E6020094 */   swc1     $f2, 0x94($s0)
.LE00A8224:
/* 3A7314 E00A8224 8E020044 */  lw        $v0, 0x44($s0)
/* 3A7318 E00A8228 8E03006C */  lw        $v1, 0x6c($s0)
/* 3A731C E00A822C 000210C0 */  sll       $v0, $v0, 3
/* 3A7320 E00A8230 00532021 */  addu      $a0, $v0, $s3
/* 3A7324 E00A8234 90820004 */  lbu       $v0, 4($a0)
/* 3A7328 E00A8238 0062102A */  slt       $v0, $v1, $v0
/* 3A732C E00A823C 14400003 */  bnez      $v0, .LE00A824C
/* 3A7330 E00A8240 00031840 */   sll      $v1, $v1, 1
/* 3A7334 E00A8244 0802A0A9 */  j         .LE00A82A4
/* 3A7338 E00A8248 AE00001C */   sw       $zero, 0x1c($s0)
.LE00A824C:
/* 3A733C E00A824C 8C820000 */  lw        $v0, ($a0)
/* 3A7340 E00A8250 00621021 */  addu      $v0, $v1, $v0
/* 3A7344 E00A8254 80420000 */  lb        $v0, ($v0)
/* 3A7348 E00A8258 C6020094 */  lwc1      $f2, 0x94($s0)
/* 3A734C E00A825C 44820000 */  mtc1      $v0, $f0
/* 3A7350 E00A8260 00000000 */  nop
/* 3A7354 E00A8264 46800020 */  cvt.s.w   $f0, $f0
/* 3A7358 E00A8268 46020002 */  mul.s     $f0, $f0, $f2
/* 3A735C E00A826C 00000000 */  nop
/* 3A7360 E00A8270 E60000BC */  swc1      $f0, 0xbc($s0)
/* 3A7364 E00A8274 8C820000 */  lw        $v0, ($a0)
/* 3A7368 E00A8278 00621821 */  addu      $v1, $v1, $v0
/* 3A736C E00A827C 80620001 */  lb        $v0, 1($v1)
/* 3A7370 E00A8280 44820000 */  mtc1      $v0, $f0
/* 3A7374 E00A8284 00000000 */  nop
/* 3A7378 E00A8288 46800020 */  cvt.s.w   $f0, $f0
/* 3A737C E00A828C 46020002 */  mul.s     $f0, $f0, $f2
/* 3A7380 E00A8290 00000000 */  nop
/* 3A7384 E00A8294 8E02006C */  lw        $v0, 0x6c($s0)
/* 3A7388 E00A8298 24420001 */  addiu     $v0, $v0, 1
/* 3A738C E00A829C AE02006C */  sw        $v0, 0x6c($s0)
/* 3A7390 E00A82A0 E60000E4 */  swc1      $f0, 0xe4($s0)
.LE00A82A4:
/* 3A7394 E00A82A4 26100004 */  addiu     $s0, $s0, 4
.LE00A82A8:
/* 3A7398 E00A82A8 26310001 */  addiu     $s1, $s1, 1
/* 3A739C E00A82AC 2A22000A */  slti      $v0, $s1, 0xa
/* 3A73A0 E00A82B0 1440FFBA */  bnez      $v0, .LE00A819C
/* 3A73A4 E00A82B4 00000000 */   nop
.LE00A82B8:
/* 3A73A8 E00A82B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A73AC E00A82BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3A73B0 E00A82C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 3A73B4 E00A82C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A73B8 E00A82C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A73BC E00A82CC 03E00008 */  jr        $ra
/* 3A73C0 E00A82D0 27BD0028 */   addiu    $sp, $sp, 0x28
