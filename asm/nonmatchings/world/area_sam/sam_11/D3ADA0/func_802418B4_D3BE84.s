.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418B4_D3BE84
/* D3BE84 802418B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3BE88 802418B8 AFB00010 */  sw        $s0, 0x10($sp)
/* D3BE8C 802418BC 0080802D */  daddu     $s0, $a0, $zero
/* D3BE90 802418C0 24040001 */  addiu     $a0, $zero, 1
/* D3BE94 802418C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* D3BE98 802418C8 AFB20018 */  sw        $s2, 0x18($sp)
/* D3BE9C 802418CC 0C00EAD2 */  jal       get_npc_safe
/* D3BEA0 802418D0 AFB10014 */   sw       $s1, 0x14($sp)
/* D3BEA4 802418D4 0040882D */  daddu     $s1, $v0, $zero
/* D3BEA8 802418D8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D3BEAC 802418DC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D3BEB0 802418E0 C60200AC */  lwc1      $f2, 0xac($s0)
/* D3BEB4 802418E4 C6200040 */  lwc1      $f0, 0x40($s1)
/* D3BEB8 802418E8 46001032 */  c.eq.s    $f2, $f0
/* D3BEBC 802418EC 00000000 */  nop       
/* D3BEC0 802418F0 45000006 */  bc1f      .L8024190C
/* D3BEC4 802418F4 261000AC */   addiu    $s0, $s0, 0xac
/* D3BEC8 802418F8 3C03009A */  lui       $v1, 0x9a
/* D3BECC 802418FC 8E220028 */  lw        $v0, 0x28($s1)
/* D3BED0 80241900 34630001 */  ori       $v1, $v1, 1
/* D3BED4 80241904 54430001 */  bnel      $v0, $v1, .L8024190C
/* D3BED8 80241908 AE230028 */   sw       $v1, 0x28($s1)
.L8024190C:
/* D3BEDC 8024190C C6020000 */  lwc1      $f2, ($s0)
/* D3BEE0 80241910 C6200040 */  lwc1      $f0, 0x40($s1)
/* D3BEE4 80241914 46001032 */  c.eq.s    $f2, $f0
/* D3BEE8 80241918 00000000 */  nop       
/* D3BEEC 8024191C 45030008 */  bc1tl     .L80241940
/* D3BEF0 80241920 E6000000 */   swc1     $f0, ($s0)
/* D3BEF4 80241924 3C03009A */  lui       $v1, 0x9a
/* D3BEF8 80241928 8E220028 */  lw        $v0, 0x28($s1)
/* D3BEFC 8024192C 34630002 */  ori       $v1, $v1, 2
/* D3BF00 80241930 54430001 */  bnel      $v0, $v1, .L80241938
/* D3BF04 80241934 AE230028 */   sw       $v1, 0x28($s1)
.L80241938:
/* D3BF08 80241938 C6200040 */  lwc1      $f0, 0x40($s1)
/* D3BF0C 8024193C E6000000 */  swc1      $f0, ($s0)
.L80241940:
/* D3BF10 80241940 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D3BF14 80241944 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D3BF18 80241948 8E460028 */  lw        $a2, 0x28($s2)
/* D3BF1C 8024194C 0C00A7B5 */  jal       dist2D
/* D3BF20 80241950 8E470030 */   lw       $a3, 0x30($s2)
/* D3BF24 80241954 3C0141F0 */  lui       $at, 0x41f0
/* D3BF28 80241958 44811000 */  mtc1      $at, $f2
/* D3BF2C 8024195C 00000000 */  nop       
/* D3BF30 80241960 4602003C */  c.lt.s    $f0, $f2
/* D3BF34 80241964 00000000 */  nop       
/* D3BF38 80241968 4501003A */  bc1t      .L80241A54
/* D3BF3C 8024196C 24020002 */   addiu    $v0, $zero, 2
/* D3BF40 80241970 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D3BF44 80241974 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D3BF48 80241978 8E460028 */  lw        $a2, 0x28($s2)
/* D3BF4C 8024197C 0C00A7B5 */  jal       dist2D
/* D3BF50 80241980 8E470030 */   lw       $a3, 0x30($s2)
/* D3BF54 80241984 3C014302 */  lui       $at, 0x4302
/* D3BF58 80241988 44811000 */  mtc1      $at, $f2
/* D3BF5C 8024198C 00000000 */  nop       
/* D3BF60 80241990 4600103C */  c.lt.s    $f2, $f0
/* D3BF64 80241994 00000000 */  nop       
/* D3BF68 80241998 4501002E */  bc1t      .L80241A54
/* D3BF6C 8024199C 24020002 */   addiu    $v0, $zero, 2
/* D3BF70 802419A0 C6420030 */  lwc1      $f2, 0x30($s2)
/* D3BF74 802419A4 3C014248 */  lui       $at, 0x4248
/* D3BF78 802419A8 44812000 */  mtc1      $at, $f4
/* D3BF7C 802419AC 00000000 */  nop       
/* D3BF80 802419B0 4602203C */  c.lt.s    $f4, $f2
/* D3BF84 802419B4 00000000 */  nop       
/* D3BF88 802419B8 45000002 */  bc1f      .L802419C4
/* D3BF8C 802419BC 46001006 */   mov.s    $f0, $f2
/* D3BF90 802419C0 46002086 */  mov.s     $f2, $f4
.L802419C4:
/* D3BF94 802419C4 3C01C220 */  lui       $at, 0xc220
/* D3BF98 802419C8 44812000 */  mtc1      $at, $f4
/* D3BF9C 802419CC 00000000 */  nop       
/* D3BFA0 802419D0 4604003C */  c.lt.s    $f0, $f4
/* D3BFA4 802419D4 00000000 */  nop       
/* D3BFA8 802419D8 45030001 */  bc1tl     .L802419E0
/* D3BFAC 802419DC 46002086 */   mov.s    $f2, $f4
.L802419E0:
/* D3BFB0 802419E0 C6240040 */  lwc1      $f4, 0x40($s1)
/* D3BFB4 802419E4 4602203E */  c.le.s    $f4, $f2
/* D3BFB8 802419E8 00000000 */  nop       
/* D3BFBC 802419EC 4500000B */  bc1f      .L80241A1C
/* D3BFC0 802419F0 00000000 */   nop      
/* D3BFC4 802419F4 3C014080 */  lui       $at, 0x4080
/* D3BFC8 802419F8 44810000 */  mtc1      $at, $f0
/* D3BFCC 802419FC 00000000 */  nop       
/* D3BFD0 80241A00 46002000 */  add.s     $f0, $f4, $f0
/* D3BFD4 80241A04 4600103C */  c.lt.s    $f2, $f0
/* D3BFD8 80241A08 00000000 */  nop       
/* D3BFDC 80241A0C 45000002 */  bc1f      .L80241A18
/* D3BFE0 80241A10 E6200040 */   swc1     $f0, 0x40($s1)
/* D3BFE4 80241A14 E6220040 */  swc1      $f2, 0x40($s1)
.L80241A18:
/* D3BFE8 80241A18 C6240040 */  lwc1      $f4, 0x40($s1)
.L80241A1C:
/* D3BFEC 80241A1C 4604103C */  c.lt.s    $f2, $f4
/* D3BFF0 80241A20 00000000 */  nop       
/* D3BFF4 80241A24 4500000B */  bc1f      .L80241A54
/* D3BFF8 80241A28 24020002 */   addiu    $v0, $zero, 2
/* D3BFFC 80241A2C 3C014080 */  lui       $at, 0x4080
/* D3C000 80241A30 44810000 */  mtc1      $at, $f0
/* D3C004 80241A34 00000000 */  nop       
/* D3C008 80241A38 46002001 */  sub.s     $f0, $f4, $f0
/* D3C00C 80241A3C 4602003E */  c.le.s    $f0, $f2
/* D3C010 80241A40 00000000 */  nop       
/* D3C014 80241A44 45000003 */  bc1f      .L80241A54
/* D3C018 80241A48 E6200040 */   swc1     $f0, 0x40($s1)
/* D3C01C 80241A4C E6220040 */  swc1      $f2, 0x40($s1)
/* D3C020 80241A50 24020002 */  addiu     $v0, $zero, 2
.L80241A54:
/* D3C024 80241A54 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3C028 80241A58 8FB20018 */  lw        $s2, 0x18($sp)
/* D3C02C 80241A5C 8FB10014 */  lw        $s1, 0x14($sp)
/* D3C030 80241A60 8FB00010 */  lw        $s0, 0x10($sp)
/* D3C034 80241A64 03E00008 */  jr        $ra
/* D3C038 80241A68 27BD0020 */   addiu    $sp, $sp, 0x20
