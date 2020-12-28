.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218150_4EF5F0
/* 4EF5F0 80218150 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EF5F4 80218154 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4EF5F8 80218158 4485B000 */  mtc1      $a1, $f22
/* 4EF5FC 8021815C 3C0140C9 */  lui       $at, 0x40c9
/* 4EF600 80218160 34210FD0 */  ori       $at, $at, 0xfd0
/* 4EF604 80218164 44810000 */  mtc1      $at, $f0
/* 4EF608 80218168 44863000 */  mtc1      $a2, $f6
/* 4EF60C 8021816C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4EF610 80218170 46003502 */  mul.s     $f20, $f6, $f0
/* 4EF614 80218174 00000000 */  nop       
/* 4EF618 80218178 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF61C 8021817C 3C0143B4 */  lui       $at, 0x43b4
/* 4EF620 80218180 44810000 */  mtc1      $at, $f0
/* 4EF624 80218184 0080802D */  daddu     $s0, $a0, $zero
/* 4EF628 80218188 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4EF62C 8021818C 4600A503 */  div.s     $f20, $f20, $f0
/* 4EF630 80218190 0C00A85B */  jal       sin_rad
/* 4EF634 80218194 4600A306 */   mov.s    $f12, $f20
/* 4EF638 80218198 4600A306 */  mov.s     $f12, $f20
/* 4EF63C 8021819C 0C00A874 */  jal       cos_rad
/* 4EF640 802181A0 46000506 */   mov.s    $f20, $f0
/* 4EF644 802181A4 4600B087 */  neg.s     $f2, $f22
/* 4EF648 802181A8 46141082 */  mul.s     $f2, $f2, $f20
/* 4EF64C 802181AC 00000000 */  nop       
/* 4EF650 802181B0 4600B582 */  mul.s     $f22, $f22, $f0
/* 4EF654 802181B4 00000000 */  nop       
/* 4EF658 802181B8 C6040000 */  lwc1      $f4, ($s0)
/* 4EF65C 802181BC 46022100 */  add.s     $f4, $f4, $f2
/* 4EF660 802181C0 C6000004 */  lwc1      $f0, 4($s0)
/* 4EF664 802181C4 46160000 */  add.s     $f0, $f0, $f22
/* 4EF668 802181C8 E6040000 */  swc1      $f4, ($s0)
/* 4EF66C 802181CC E6000004 */  swc1      $f0, 4($s0)
/* 4EF670 802181D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4EF674 802181D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF678 802181D8 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4EF67C 802181DC D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4EF680 802181E0 03E00008 */  jr        $ra
/* 4EF684 802181E4 27BD0028 */   addiu    $sp, $sp, 0x28
