.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B1B4
.L8006B1B4:
/* 465B4 8006B1B4 3C048009 */  lui       $a0, %hi(D_80094638)
/* 465B8 8006B1B8 0C01AC67 */  jal       func_8006B19C
/* 465BC 8006B1BC 24844638 */   addiu    $a0, $a0, %lo(D_80094638)
/* 465C0 8006B1C0 3C018009 */  lui       $at, %hi(D_80094640)
/* 465C4 8006B1C4 AC224640 */  sw        $v0, %lo(D_80094640)($at)
/* 465C8 8006B1C8 24080004 */  addiu     $t0, $zero, 4
/* 465CC 8006B1CC A4480010 */  sh        $t0, 0x10($v0)
/* 465D0 8006B1D0 0040D021 */  addu      $k0, $v0, $zero
/* 465D4 8006B1D4 8F5B0118 */  lw        $k1, 0x118($k0)
/* 465D8 8006B1D8 3C088009 */  lui       $t0, %hi(D_80095890)
/* 465DC 8006B1DC 25085890 */  addiu     $t0, $t0, %lo(D_80095890)
/* 465E0 8006B1E0 8D080000 */  lw        $t0, ($t0)
/* 465E4 8006B1E4 3108FF00 */  andi      $t0, $t0, 0xff00
/* 465E8 8006B1E8 3369FF00 */  andi      $t1, $k1, 0xff00
/* 465EC 8006B1EC 01284824 */  and       $t1, $t1, $t0
/* 465F0 8006B1F0 3C01FFFF */  lui       $at, 0xffff
/* 465F4 8006B1F4 342100FF */  ori       $at, $at, 0xff
/* 465F8 8006B1F8 0361D824 */  and       $k1, $k1, $at
/* 465FC 8006B1FC 0369D825 */  or        $k1, $k1, $t1
/* 46600 8006B200 409B6000 */  mtc0      $k1, $12
/* 46604 8006B204 DF410020 */  ld        $at, 0x20($k0)
/* 46608 8006B208 DF420028 */  ld        $v0, 0x28($k0)
/* 4660C 8006B20C DF430030 */  ld        $v1, 0x30($k0)
/* 46610 8006B210 DF440038 */  ld        $a0, 0x38($k0)
/* 46614 8006B214 DF450040 */  ld        $a1, 0x40($k0)
/* 46618 8006B218 DF460048 */  ld        $a2, 0x48($k0)
/* 4661C 8006B21C DF470050 */  ld        $a3, 0x50($k0)
/* 46620 8006B220 DF480058 */  ld        $t0, 0x58($k0)
/* 46624 8006B224 DF490060 */  ld        $t1, 0x60($k0)
/* 46628 8006B228 DF4A0068 */  ld        $t2, 0x68($k0)
/* 4662C 8006B22C DF4B0070 */  ld        $t3, 0x70($k0)
/* 46630 8006B230 DF4C0078 */  ld        $t4, 0x78($k0)
/* 46634 8006B234 DF4D0080 */  ld        $t5, 0x80($k0)
/* 46638 8006B238 DF4E0088 */  ld        $t6, 0x88($k0)
/* 4663C 8006B23C DF4F0090 */  ld        $t7, 0x90($k0)
/* 46640 8006B240 DF500098 */  ld        $s0, 0x98($k0)
/* 46644 8006B244 DF5100A0 */  ld        $s1, 0xa0($k0)
/* 46648 8006B248 DF5200A8 */  ld        $s2, 0xa8($k0)
/* 4664C 8006B24C DF5300B0 */  ld        $s3, 0xb0($k0)
/* 46650 8006B250 DF5400B8 */  ld        $s4, 0xb8($k0)
/* 46654 8006B254 DF5500C0 */  ld        $s5, 0xc0($k0)
/* 46658 8006B258 DF5600C8 */  ld        $s6, 0xc8($k0)
/* 4665C 8006B25C DF5700D0 */  ld        $s7, 0xd0($k0)
/* 46660 8006B260 DF5800D8 */  ld        $t8, 0xd8($k0)
/* 46664 8006B264 DF5900E0 */  ld        $t9, 0xe0($k0)
/* 46668 8006B268 DF5C00E8 */  ld        $gp, 0xe8($k0)
/* 4666C 8006B26C DF5D00F0 */  ld        $sp, 0xf0($k0)
/* 46670 8006B270 DF5E00F8 */  ld        $fp, 0xf8($k0)
/* 46674 8006B274 DF5F0100 */  ld        $ra, 0x100($k0)
/* 46678 8006B278 DF5B0108 */  ld        $k1, 0x108($k0)
/* 4667C 8006B27C 03600013 */  mtlo      $k1
/* 46680 8006B280 DF5B0110 */  ld        $k1, 0x110($k0)
/* 46684 8006B284 03600011 */  mthi      $k1
/* 46688 8006B288 8F5B011C */  lw        $k1, 0x11c($k0)
/* 4668C 8006B28C 409B7000 */  mtc0      $k1, $14
/* 46690 8006B290 8F5B0018 */  lw        $k1, 0x18($k0)
/* 46694 8006B294 13600013 */  beqz      $k1, .L8006B2E4
/* 46698 8006B298 00000000 */   nop
/* 4669C 8006B29C 8F5B012C */  lw        $k1, 0x12c($k0)
/* 466A0 8006B2A0 44DBF800 */  ctc1      $k1, $31
/* 466A4 8006B2A4 D7400130 */  ldc1      $f0, 0x130($k0)
/* 466A8 8006B2A8 D7420138 */  ldc1      $f2, 0x138($k0)
/* 466AC 8006B2AC D7440140 */  ldc1      $f4, 0x140($k0)
/* 466B0 8006B2B0 D7460148 */  ldc1      $f6, 0x148($k0)
/* 466B4 8006B2B4 D7480150 */  ldc1      $f8, 0x150($k0)
/* 466B8 8006B2B8 D74A0158 */  ldc1      $f10, 0x158($k0)
/* 466BC 8006B2BC D74C0160 */  ldc1      $f12, 0x160($k0)
/* 466C0 8006B2C0 D74E0168 */  ldc1      $f14, 0x168($k0)
/* 466C4 8006B2C4 D7500170 */  ldc1      $f16, 0x170($k0)
/* 466C8 8006B2C8 D7520178 */  ldc1      $f18, 0x178($k0)
/* 466CC 8006B2CC D7540180 */  ldc1      $f20, 0x180($k0)
/* 466D0 8006B2D0 D7560188 */  ldc1      $f22, 0x188($k0)
/* 466D4 8006B2D4 D7580190 */  ldc1      $f24, 0x190($k0)
/* 466D8 8006B2D8 D75A0198 */  ldc1      $f26, 0x198($k0)
/* 466DC 8006B2DC D75C01A0 */  ldc1      $f28, 0x1a0($k0)
/* 466E0 8006B2E0 D75E01A8 */  ldc1      $f30, 0x1a8($k0)
.L8006B2E4:
/* 466E4 8006B2E4 8F5B0128 */  lw        $k1, 0x128($k0)
/* 466E8 8006B2E8 3C1A8009 */  lui       $k0, %hi(D_80095890)
/* 466EC 8006B2EC 275A5890 */  addiu     $k0, $k0, %lo(D_80095890)
/* 466F0 8006B2F0 8F5A0000 */  lw        $k0, ($k0)
/* 466F4 8006B2F4 001AD402 */  srl       $k0, $k0, 0x10
/* 466F8 8006B2F8 037AD824 */  and       $k1, $k1, $k0
/* 466FC 8006B2FC 001BD840 */  sll       $k1, $k1, 1
/* 46700 8006B300 3C1A800A */  lui       $k0, %hi(D_80099A80)
/* 46704 8006B304 275A9A80 */  addiu     $k0, $k0, %lo(D_80099A80)
/* 46708 8006B308 037AD821 */  addu      $k1, $k1, $k0
/* 4670C 8006B30C 977B0000 */  lhu       $k1, ($k1)
/* 46710 8006B310 3C1AA430 */  lui       $k0, 0xa430
/* 46714 8006B314 375A000C */  ori       $k0, $k0, 0xc
/* 46718 8006B318 AF5B0000 */  sw        $k1, ($k0)
/* 4671C 8006B31C 00000000 */  nop
/* 46720 8006B320 00000000 */  nop
/* 46724 8006B324 00000000 */  nop
/* 46728 8006B328 00000000 */  nop
/* 4672C 8006B32C 42000018 */  eret
/* 46730 8006B330 00002021 */  addu      $a0, $zero, $zero
/* 46734 8006B334 0C01B24C */  jal       func_8006C930
/* 46738 8006B338 00000000 */   nop
/* 4673C 8006B33C 00000000 */  nop
