.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E00789D0
.double 0.6, 0.0

.section .text

glabel bulb_glow_update
/* 37A51C E007812C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 37A520 E0078130 AFBF0010 */  sw        $ra, 0x10($sp)
/* 37A524 E0078134 8C850000 */  lw        $a1, ($a0)
/* 37A528 E0078138 8C83000C */  lw        $v1, 0xc($a0)
/* 37A52C E007813C 30A20010 */  andi      $v0, $a1, 0x10
/* 37A530 E0078140 10400005 */  beqz      $v0, .LE0078158
/* 37A534 E0078144 2402FFEF */   addiu    $v0, $zero, -0x11
/* 37A538 E0078148 00A21024 */  and       $v0, $a1, $v0
/* 37A53C E007814C AC820000 */  sw        $v0, ($a0)
/* 37A540 E0078150 2402000A */  addiu     $v0, $zero, 0xa
/* 37A544 E0078154 AC620014 */  sw        $v0, 0x14($v1)
.LE0078158:
/* 37A548 E0078158 8C620018 */  lw        $v0, 0x18($v1)
/* 37A54C E007815C 8C650014 */  lw        $a1, 0x14($v1)
/* 37A550 E0078160 24420001 */  addiu     $v0, $v0, 1
/* 37A554 E0078164 AC620018 */  sw        $v0, 0x18($v1)
/* 37A558 E0078168 28A20064 */  slti      $v0, $a1, 0x64
/* 37A55C E007816C 10400002 */  beqz      $v0, .LE0078178
/* 37A560 E0078170 24A2FFFF */   addiu    $v0, $a1, -1
/* 37A564 E0078174 AC620014 */  sw        $v0, 0x14($v1)
.LE0078178:
/* 37A568 E0078178 8C620014 */  lw        $v0, 0x14($v1)
/* 37A56C E007817C 04410005 */  bgez      $v0, .LE0078194
/* 37A570 E0078180 00000000 */   nop
/* 37A574 E0078184 0C080128 */  jal       shim_remove_effect
/* 37A578 E0078188 00000000 */   nop
/* 37A57C E007818C 0801E081 */  j         .LE0078204
/* 37A580 E0078190 00000000 */   nop
.LE0078194:
/* 37A584 E0078194 8C620000 */  lw        $v0, ($v1)
/* 37A588 E0078198 8C640018 */  lw        $a0, 0x18($v1)
/* 37A58C E007819C 14400019 */  bnez      $v0, .LE0078204
/* 37A590 E00781A0 2882000B */   slti     $v0, $a0, 0xb
/* 37A594 E00781A4 10400005 */  beqz      $v0, .LE00781BC
/* 37A598 E00781A8 00041040 */   sll      $v0, $a0, 1
/* 37A59C E00781AC 00441021 */  addu      $v0, $v0, $a0
/* 37A5A0 E00781B0 00021040 */  sll       $v0, $v0, 1
/* 37A5A4 E00781B4 0801E070 */  j         .LE00781C0
/* 37A5A8 E00781B8 24420004 */   addiu    $v0, $v0, 4
.LE00781BC:
/* 37A5AC E00781BC 24020040 */  addiu     $v0, $zero, 0x40
.LE00781C0:
/* 37A5B0 E00781C0 AC620010 */  sw        $v0, 0x10($v1)
/* 37A5B4 E00781C4 30820001 */  andi      $v0, $a0, 1
/* 37A5B8 E00781C8 10400009 */  beqz      $v0, .LE00781F0
/* 37A5BC E00781CC 2882000F */   slti     $v0, $a0, 0xf
/* 37A5C0 E00781D0 3C01E008 */  lui       $at, %hi(D_E00789D0)
/* 37A5C4 E00781D4 D42289D0 */  ldc1      $f2, %lo(D_E00789D0)($at)
/* 37A5C8 E00781D8 C4600010 */  lwc1      $f0, 0x10($v1)
/* 37A5CC E00781DC 46800021 */  cvt.d.w   $f0, $f0
/* 37A5D0 E00781E0 46220002 */  mul.d     $f0, $f0, $f2
/* 37A5D4 E00781E4 00000000 */  nop
/* 37A5D8 E00781E8 4620010D */  trunc.w.d $f4, $f0
/* 37A5DC E00781EC E4640010 */  swc1      $f4, 0x10($v1)
.LE00781F0:
/* 37A5E0 E00781F0 14400004 */  bnez      $v0, .LE0078204
/* 37A5E4 E00781F4 24020004 */   addiu    $v0, $zero, 4
/* 37A5E8 E00781F8 AC620000 */  sw        $v0, ($v1)
/* 37A5EC E00781FC 2402007F */  addiu     $v0, $zero, 0x7f
/* 37A5F0 E0078200 AC620010 */  sw        $v0, 0x10($v1)
.LE0078204:
/* 37A5F4 E0078204 8FBF0010 */  lw        $ra, 0x10($sp)
/* 37A5F8 E0078208 03E00008 */  jr        $ra
/* 37A5FC E007820C 27BD0018 */   addiu    $sp, $sp, 0x18
