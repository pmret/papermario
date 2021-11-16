.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80247A20_B52490
.double 0.2, 0.0

.section .text

glabel func_802406DC_B4B14C
/* B4B14C 802406DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4B150 802406E0 AFB00010 */  sw        $s0, 0x10($sp)
/* B4B154 802406E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B4B158 802406E8 4485A000 */  mtc1      $a1, $f20
/* B4B15C 802406EC AFBF0014 */  sw        $ra, 0x14($sp)
/* B4B160 802406F0 0C019D28 */  jal       guMtxIdentF
/* B4B164 802406F4 0080802D */   daddu    $s0, $a0, $zero
/* B4B168 802406F8 3C018024 */  lui       $at, %hi(D_80247A20_B52490)
/* B4B16C 802406FC D4207A20 */  ldc1      $f0, %lo(D_80247A20_B52490)($at)
/* B4B170 80240700 4600A521 */  cvt.d.s   $f20, $f20
/* B4B174 80240704 4620A502 */  mul.d     $f20, $f20, $f0
/* B4B178 80240708 00000000 */  nop
/* B4B17C 8024070C 3C013F80 */  lui       $at, 0x3f80
/* B4B180 80240710 44810000 */  mtc1      $at, $f0
/* B4B184 80240714 AE000018 */  sw        $zero, 0x18($s0)
/* B4B188 80240718 E6000014 */  swc1      $f0, 0x14($s0)
/* B4B18C 8024071C 4620A520 */  cvt.s.d   $f20, $f20
/* B4B190 80240720 E6140010 */  swc1      $f20, 0x10($s0)
/* B4B194 80240724 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4B198 80240728 8FB00010 */  lw        $s0, 0x10($sp)
/* B4B19C 8024072C D7B40018 */  ldc1      $f20, 0x18($sp)
/* B4B1A0 80240730 03E00008 */  jr        $ra
/* B4B1A4 80240734 27BD0020 */   addiu    $sp, $sp, 0x20
