.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_92_main
/* 3B7B80 E00B8000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B7B84 E00B8004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B7B88 E00B8008 4485A000 */  mtc1      $a1, $f20
/* 3B7B8C E00B800C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B7B90 E00B8010 4486B000 */  mtc1      $a2, $f22
/* 3B7B94 E00B8014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B7B98 E00B8018 0080902D */  daddu     $s2, $a0, $zero
/* 3B7B9C E00B801C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B7BA0 E00B8020 4487C000 */  mtc1      $a3, $f24
/* 3B7BA4 E00B8024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B7BA8 E00B8028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B7BAC E00B802C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3B7BB0 E00B8030 3C02E00C */  lui       $v0, %hi(fx_92_init)
/* 3B7BB4 E00B8034 2442812C */  addiu     $v0, $v0, %lo(fx_92_init)
/* 3B7BB8 E00B8038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B7BBC E00B803C 3C02E00C */  lui       $v0, %hi(fx_92_update)
/* 3B7BC0 E00B8040 24428134 */  addiu     $v0, $v0, %lo(fx_92_update)
/* 3B7BC4 E00B8044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B7BC8 E00B8048 3C02E00C */  lui       $v0, %hi(fx_92_render)
/* 3B7BCC E00B804C 244281B8 */  addiu     $v0, $v0, %lo(fx_92_render)
/* 3B7BD0 E00B8050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B7BD4 E00B8054 2402005C */  addiu     $v0, $zero, 0x5c
/* 3B7BD8 E00B8058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B7BDC E00B805C AFB00028 */  sw        $s0, 0x28($sp)
/* 3B7BE0 E00B8060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B7BE4 E00B8064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B7BE8 E00B8068 0C080124 */  jal       shim_create_effect_instance
/* 3B7BEC E00B806C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B7BF0 E00B8070 24040044 */  addiu     $a0, $zero, 0x44
/* 3B7BF4 E00B8074 24030001 */  addiu     $v1, $zero, 1
/* 3B7BF8 E00B8078 0040802D */  daddu     $s0, $v0, $zero
/* 3B7BFC E00B807C 0C08012C */  jal       shim_general_heap_malloc
/* 3B7C00 E00B8080 AE030008 */   sw       $v1, 8($s0)
/* 3B7C04 E00B8084 0040282D */  daddu     $a1, $v0, $zero
/* 3B7C08 E00B8088 14A00003 */  bnez      $a1, .LE00B8098
/* 3B7C0C E00B808C AE02000C */   sw       $v0, 0xc($s0)
.LE00B8090:
/* 3B7C10 E00B8090 0802E024 */  j         .LE00B8090
/* 3B7C14 E00B8094 00000000 */   nop
.LE00B8098:
/* 3B7C18 E00B8098 ACB20000 */  sw        $s2, ($a1)
/* 3B7C1C E00B809C 1E200004 */  bgtz      $s1, .LE00B80B0
/* 3B7C20 E00B80A0 ACA00014 */   sw       $zero, 0x14($a1)
/* 3B7C24 E00B80A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B7C28 E00B80A8 0802E02D */  j         .LE00B80B4
/* 3B7C2C E00B80AC ACA20010 */   sw       $v0, 0x10($a1)
.LE00B80B0:
/* 3B7C30 E00B80B0 ACB10010 */  sw        $s1, 0x10($a1)
.LE00B80B4:
/* 3B7C34 E00B80B4 0200102D */  daddu     $v0, $s0, $zero
/* 3B7C38 E00B80B8 240400FF */  addiu     $a0, $zero, 0xff
/* 3B7C3C E00B80BC ACA40024 */  sw        $a0, 0x24($a1)
/* 3B7C40 E00B80C0 E4B40004 */  swc1      $f20, 4($a1)
/* 3B7C44 E00B80C4 E4B60008 */  swc1      $f22, 8($a1)
/* 3B7C48 E00B80C8 E4B8000C */  swc1      $f24, 0xc($a1)
/* 3B7C4C E00B80CC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3B7C50 E00B80D0 24030046 */  addiu     $v1, $zero, 0x46
/* 3B7C54 E00B80D4 ACA30018 */  sw        $v1, 0x18($a1)
/* 3B7C58 E00B80D8 E4A00034 */  swc1      $f0, 0x34($a1)
/* 3B7C5C E00B80DC 3C013F80 */  lui       $at, 0x3f80
/* 3B7C60 E00B80E0 44810000 */  mtc1      $at, $f0
/* 3B7C64 E00B80E4 240300B4 */  addiu     $v1, $zero, 0xb4
/* 3B7C68 E00B80E8 ACA3001C */  sw        $v1, 0x1c($a1)
/* 3B7C6C E00B80EC ACA40020 */  sw        $a0, 0x20($a1)
/* 3B7C70 E00B80F0 ACA40028 */  sw        $a0, 0x28($a1)
/* 3B7C74 E00B80F4 ACA4002C */  sw        $a0, 0x2c($a1)
/* 3B7C78 E00B80F8 ACA40030 */  sw        $a0, 0x30($a1)
/* 3B7C7C E00B80FC ACA00038 */  sw        $zero, 0x38($a1)
/* 3B7C80 E00B8100 E4A0003C */  swc1      $f0, 0x3c($a1)
/* 3B7C84 E00B8104 E4A00040 */  swc1      $f0, 0x40($a1)
/* 3B7C88 E00B8108 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B7C8C E00B810C 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B7C90 E00B8110 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B7C94 E00B8114 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B7C98 E00B8118 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B7C9C E00B811C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B7CA0 E00B8120 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B7CA4 E00B8124 03E00008 */  jr        $ra
/* 3B7CA8 E00B8128 27BD0050 */   addiu    $sp, $sp, 0x50
