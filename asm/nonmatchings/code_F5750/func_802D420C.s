.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D420C
/* F8BBC 802D420C 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F8BC0 802D4210 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F8BC4 802D4214 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F8BC8 802D4218 AFB10014 */  sw        $s1, 0x14($sp)
/* F8BCC 802D421C 0000882D */  daddu     $s1, $zero, $zero
/* F8BD0 802D4220 AFBF0018 */  sw        $ra, 0x18($sp)
/* F8BD4 802D4224 AFB00010 */  sw        $s0, 0x10($sp)
.L802D4228:
/* F8BD8 802D4228 8C700000 */  lw        $s0, ($v1)
/* F8BDC 802D422C 8E020000 */  lw        $v0, ($s0)
/* F8BE0 802D4230 04400006 */  bltz      $v0, .L802D424C
/* F8BE4 802D4234 2A220040 */   slti     $v0, $s1, 0x40
/* F8BE8 802D4238 26310001 */  addiu     $s1, $s1, 1
/* F8BEC 802D423C 2A220040 */  slti      $v0, $s1, 0x40
/* F8BF0 802D4240 1440FFF9 */  bnez      $v0, .L802D4228
/* F8BF4 802D4244 24630004 */   addiu    $v1, $v1, 4
/* F8BF8 802D4248 2A220040 */  slti      $v0, $s1, 0x40
.L802D424C:
/* F8BFC 802D424C 50400012 */  beql      $v0, $zero, .L802D4298
/* F8C00 802D4250 0000102D */   daddu    $v0, $zero, $zero
/* F8C04 802D4254 0C048338 */  jal       load_virtual_model
/* F8C08 802D4258 00000000 */   nop
/* F8C0C 802D425C 3C013F80 */  lui       $at, 0x3f80
/* F8C10 802D4260 44810000 */  mtc1      $at, $f0
/* F8C14 802D4264 AE020000 */  sw        $v0, ($s0)
/* F8C18 802D4268 0040202D */  daddu     $a0, $v0, $zero
/* F8C1C 802D426C AE000004 */  sw        $zero, 4($s0)
/* F8C20 802D4270 AE000008 */  sw        $zero, 8($s0)
/* F8C24 802D4274 AE00000C */  sw        $zero, 0xc($s0)
/* F8C28 802D4278 AE000010 */  sw        $zero, 0x10($s0)
/* F8C2C 802D427C AE000014 */  sw        $zero, 0x14($s0)
/* F8C30 802D4280 AE000018 */  sw        $zero, 0x18($s0)
/* F8C34 802D4284 E600001C */  swc1      $f0, 0x1c($s0)
/* F8C38 802D4288 E6000020 */  swc1      $f0, 0x20($s0)
/* F8C3C 802D428C 0C0483C1 */  jal       func_80120F04
/* F8C40 802D4290 E6000024 */   swc1     $f0, 0x24($s0)
/* F8C44 802D4294 0220102D */  daddu     $v0, $s1, $zero
.L802D4298:
/* F8C48 802D4298 8FBF0018 */  lw        $ra, 0x18($sp)
/* F8C4C 802D429C 8FB10014 */  lw        $s1, 0x14($sp)
/* F8C50 802D42A0 8FB00010 */  lw        $s0, 0x10($sp)
/* F8C54 802D42A4 03E00008 */  jr        $ra
/* F8C58 802D42A8 27BD0020 */   addiu    $sp, $sp, 0x20
