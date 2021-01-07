.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D50860
/* D50860 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D50864 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D50868 80240878 4480B000 */  mtc1      $zero, $f22
/* D5086C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D50870 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D50874 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D50878 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D5087C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D50880 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D50884 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D50888 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D5088C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D50890 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D50894 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D50898 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D5089C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D508A0 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D508A4 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D508A8 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D508AC 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D508B0 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D508B4 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D508B8 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D508BC 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D508C0 802408D0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D508C4 802408D4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D508C8 802408D8 00031080 */  sll       $v0, $v1, 2
/* D508CC 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D508D0 802408E0 00021080 */  sll       $v0, $v0, 2
/* D508D4 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D508D8 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D508DC 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D508E0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D508E4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D508E8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D508EC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D508F0 80240900 46000507 */   neg.s    $f20, $f0
/* D508F4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D508F8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D508FC 8024090C 44810000 */  mtc1      $at, $f0
/* D50900 80240910 00000000 */  nop       
/* D50904 80240914 4602003C */  c.lt.s    $f0, $f2
/* D50908 80240918 00000000 */  nop       
/* D5090C 8024091C 4500000A */  bc1f      .L80240948
/* D50910 80240920 00000000 */   nop      
/* D50914 80240924 3C014334 */  lui       $at, 0x4334
/* D50918 80240928 44812000 */  mtc1      $at, $f4
/* D5091C 8024092C 00000000 */  nop       
/* D50920 80240930 4604103E */  c.le.s    $f2, $f4
/* D50924 80240934 00000000 */  nop       
/* D50928 80240938 45000003 */  bc1f      .L80240948
/* D5092C 8024093C 00000000 */   nop      
/* D50930 80240940 08090276 */  j         .L802409D8
/* D50934 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D50938 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D5093C 8024094C 3C014334 */  lui       $at, 0x4334
/* D50940 80240950 44812000 */  mtc1      $at, $f4
/* D50944 80240954 00000000 */  nop       
/* D50948 80240958 4600203C */  c.lt.s    $f4, $f0
/* D5094C 8024095C 00000000 */  nop       
/* D50950 80240960 4500000C */  bc1f      .L80240994
/* D50954 80240964 00000000 */   nop      
/* D50958 80240968 3C014387 */  lui       $at, 0x4387
/* D5095C 8024096C 44812000 */  mtc1      $at, $f4
/* D50960 80240970 00000000 */  nop       
/* D50964 80240974 4604003E */  c.le.s    $f0, $f4
/* D50968 80240978 00000000 */  nop       
/* D5096C 8024097C 45000008 */  bc1f      .L802409A0
/* D50970 80240980 00000000 */   nop      
/* D50974 80240984 3C014334 */  lui       $at, 0x4334
/* D50978 80240988 44812000 */  mtc1      $at, $f4
/* D5097C 8024098C 08090276 */  j         .L802409D8
/* D50980 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D50984 80240994 3C014387 */  lui       $at, 0x4387
/* D50988 80240998 44812000 */  mtc1      $at, $f4
/* D5098C 8024099C 00000000 */  nop       
.L802409A0:
/* D50990 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D50994 802409A4 00000000 */  nop       
/* D50998 802409A8 4500000A */  bc1f      .L802409D4
/* D5099C 802409AC 00000000 */   nop      
/* D509A0 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D509A4 802409B4 44811000 */  mtc1      $at, $f2
/* D509A8 802409B8 00000000 */  nop       
/* D509AC 802409BC 4602003E */  c.le.s    $f0, $f2
/* D509B0 802409C0 00000000 */  nop       
/* D509B4 802409C4 45000003 */  bc1f      .L802409D4
/* D509B8 802409C8 00000000 */   nop      
/* D509BC 802409CC 08090276 */  j         .L802409D8
/* D509C0 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D509C4 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D509C8 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D509CC 802409DC 44810000 */  mtc1      $at, $f0
/* D509D0 802409E0 00000000 */  nop       
/* D509D4 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D509D8 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D509DC 802409EC 44072000 */  mfc1      $a3, $f4
/* D509E0 802409F0 00000000 */  nop       
/* D509E4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D509E8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D509EC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D509F0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D509F4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D509F8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D509FC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D50A00 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D50A04 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D50A08 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D50A0C 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D50A10 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D50A14 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D50A18 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D50A1C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D50A20 80240A30 4405A000 */  mfc1      $a1, $f20
/* D50A24 80240A34 4406B000 */  mfc1      $a2, $f22
/* D50A28 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D50A2C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D50A30 80240A40 0C019EC8 */  jal       guRotateF
/* D50A34 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D50A38 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D50A3C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D50A40 80240A50 00000000 */   nop      
/* D50A44 80240A54 44050000 */  mfc1      $a1, $f0
/* D50A48 80240A58 4406B000 */  mfc1      $a2, $f22
/* D50A4C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D50A50 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D50A54 80240A64 44812000 */  mtc1      $at, $f4
/* D50A58 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D50A5C 80240A6C 0C019EC8 */  jal       guRotateF
/* D50A60 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D50A64 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D50A68 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D50A6C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D50A70 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D50A74 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D50A78 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D50A7C 80240A8C 080902D6 */  j         .L80240B58
/* D50A80 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D50A84 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D50A88 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D50A8C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D50A90 80240AA0 0C03964E */  jal       func_800E5938
/* D50A94 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D50A98 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D50A9C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D50AA0 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D50AA4 80240AB4 46000606 */   mov.s    $f24, $f0
/* D50AA8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D50AAC 80240ABC 080902B5 */  j         .L80240AD4
/* D50AB0 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D50AB4 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D50AB8 80240AC8 00000000 */  nop       
/* D50ABC 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D50AC0 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D50AC4 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D50AC8 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D50ACC 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D50AD0 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D50AD4 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D50AD8 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D50ADC 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D50AE0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D50AE4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D50AE8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D50AEC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D50AF0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D50AF4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D50AF8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D50AFC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D50B00 80240B10 0C019EC8 */  jal       guRotateF
/* D50B04 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D50B08 80240B18 4405A000 */  mfc1      $a1, $f20
/* D50B0C 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D50B10 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D50B14 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D50B18 80240B28 0C019EC8 */  jal       guRotateF
/* D50B1C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D50B20 80240B30 4405C000 */  mfc1      $a1, $f24
/* D50B24 80240B34 4406B000 */  mfc1      $a2, $f22
/* D50B28 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D50B2C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D50B30 80240B40 0C019EC8 */  jal       guRotateF
/* D50B34 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D50B38 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D50B3C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D50B40 80240B50 0C019D80 */  jal       guMtxCatF
/* D50B44 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D50B48 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D50B4C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D50B50 80240B60 44812000 */  mtc1      $at, $f4
/* D50B54 80240B64 00021023 */  negu      $v0, $v0
/* D50B58 80240B68 44820000 */  mtc1      $v0, $f0
/* D50B5C 80240B6C 00000000 */  nop       
/* D50B60 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D50B64 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D50B68 80240B78 00000000 */  nop       
/* D50B6C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D50B70 80240B80 4407B000 */  mfc1      $a3, $f22
/* D50B74 80240B84 44062000 */  mfc1      $a2, $f4
/* D50B78 80240B88 0C019E40 */  jal       guTranslateF
/* D50B7C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D50B80 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D50B84 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D50B88 80240B98 0C019D80 */  jal       guMtxCatF
/* D50B8C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D50B90 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D50B94 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D50B98 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D50B9C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D50BA0 80240BB0 0C019EC8 */  jal       guRotateF
/* D50BA4 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D50BA8 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D50BAC 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D50BB0 80240BC0 0C019D80 */  jal       guMtxCatF
/* D50BB4 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D50BB8 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D50BBC 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D50BC0 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D50BC4 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D50BC8 80240BD8 0C019EC8 */  jal       guRotateF
/* D50BCC 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D50BD0 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D50BD4 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D50BD8 80240BE8 0C019D80 */  jal       guMtxCatF
/* D50BDC 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D50BE0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D50BE4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D50BE8 80240BF8 44812000 */  mtc1      $at, $f4
/* D50BEC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D50BF0 80240C00 00000000 */  nop       
/* D50BF4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D50BF8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D50BFC 80240C0C 00000000 */  nop       
/* D50C00 80240C10 4405B000 */  mfc1      $a1, $f22
/* D50C04 80240C14 4407B000 */  mfc1      $a3, $f22
/* D50C08 80240C18 44062000 */  mfc1      $a2, $f4
/* D50C0C 80240C1C 0C019E40 */  jal       guTranslateF
/* D50C10 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D50C14 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D50C18 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D50C1C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D50C20 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D50C24 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D50C28 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D50C2C 80240C3C 44810000 */  mtc1      $at, $f0
/* D50C30 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D50C34 80240C44 44050000 */  mfc1      $a1, $f0
/* D50C38 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D50C3C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D50C40 80240C50 0C019DF0 */  jal       guScaleF
/* D50C44 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D50C48 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D50C4C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D50C50 80240C60 0C019D80 */  jal       guMtxCatF
/* D50C54 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D50C58 80240C68 4600D687 */  neg.s     $f26, $f26
/* D50C5C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D50C60 80240C70 4407E000 */  mfc1      $a3, $f28
/* D50C64 80240C74 4406D000 */  mfc1      $a2, $f26
/* D50C68 80240C78 0C019E40 */  jal       guTranslateF
/* D50C6C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D50C70 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D50C74 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D50C78 80240C88 0C019D80 */  jal       guMtxCatF
/* D50C7C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D50C80 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D50C84 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D50C88 80240C98 44810000 */  mtc1      $at, $f0
/* D50C8C 80240C9C 00000000 */  nop       
/* D50C90 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D50C94 80240CA4 00000000 */  nop       
/* D50C98 80240CA8 4500000A */  bc1f      .L80240CD4
/* D50C9C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D50CA0 80240CB0 3C014387 */  lui       $at, 0x4387
/* D50CA4 80240CB4 44812000 */  mtc1      $at, $f4
/* D50CA8 80240CB8 00000000 */  nop       
/* D50CAC 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D50CB0 80240CC0 00000000 */  nop       
/* D50CB4 80240CC4 45000004 */  bc1f      .L80240CD8
/* D50CB8 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D50CBC 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D50CC0 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D50CC4 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D50CC8 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D50CCC 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D50CD0 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D50CD4 80240CE4 0C0B7710 */  jal       render_sprite
/* D50CD8 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D50CDC 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D50CE0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D50CE4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D50CE8 80240CF8 00000000 */   nop      
/* D50CEC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D50CF0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D50CF4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D50CF8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D50CFC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D50D00 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D50D04 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D50D08 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D50D0C 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D50D10 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D50D14 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D50D18 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D50D1C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D50D20 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D50D24 80240D34 03E00008 */  jr        $ra
/* D50D28 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
