.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osEnqueueAndYield
/* 4646C 8006B06C 3C058009 */  lui       $a1, 0x8009
/* 46470 8006B070 8CA54660 */  lw        $a1, 0x4660($a1)
/* 46474 8006B074 40086000 */  mfc0      $t0, $12
/* 46478 8006B078 35080002 */  ori       $t0, $t0, 2
/* 4647C 8006B07C ACA80118 */  sw        $t0, 0x118($a1)
/* 46480 8006B080 FCB00098 */  sd        $s0, 0x98($a1)
/* 46484 8006B084 FCB100A0 */  sd        $s1, 0xa0($a1)
/* 46488 8006B088 FCB200A8 */  sd        $s2, 0xa8($a1)
/* 4648C 8006B08C FCB300B0 */  sd        $s3, 0xb0($a1)
/* 46490 8006B090 FCB400B8 */  sd        $s4, 0xb8($a1)
/* 46494 8006B094 FCB500C0 */  sd        $s5, 0xc0($a1)
/* 46498 8006B098 FCB600C8 */  sd        $s6, 0xc8($a1)
/* 4649C 8006B09C FCB700D0 */  sd        $s7, 0xd0($a1)
/* 464A0 8006B0A0 FCBC00E8 */  sd        $gp, 0xe8($a1)
/* 464A4 8006B0A4 FCBD00F0 */  sd        $sp, 0xf0($a1)
/* 464A8 8006B0A8 FCBE00F8 */  sd        $fp, 0xf8($a1)
/* 464AC 8006B0AC FCBF0100 */  sd        $ra, 0x100($a1)
/* 464B0 8006B0B0 ACBF011C */  sw        $ra, 0x11c($a1)
/* 464B4 8006B0B4 8CBB0018 */  lw        $k1, 0x18($a1)
/* 464B8 8006B0B8 1360000A */  beqz      $k1, .L8006B0E4
/* 464BC 8006B0BC 00000000 */   nop      
/* 464C0 8006B0C0 445BF800 */  cfc1      $k1, $31
/* 464C4 8006B0C4 00000000 */  nop       
/* 464C8 8006B0C8 ACBB012C */  sw        $k1, 0x12c($a1)
/* 464CC 8006B0CC F4B40180 */  sdc1      $f20, 0x180($a1)
/* 464D0 8006B0D0 F4B60188 */  sdc1      $f22, 0x188($a1)
/* 464D4 8006B0D4 F4B80190 */  sdc1      $f24, 0x190($a1)
/* 464D8 8006B0D8 F4BA0198 */  sdc1      $f26, 0x198($a1)
/* 464DC 8006B0DC F4BC01A0 */  sdc1      $f28, 0x1a0($a1)
/* 464E0 8006B0E0 F4BE01A8 */  sdc1      $f30, 0x1a8($a1)
.L8006B0E4:
/* 464E4 8006B0E4 8CBB0118 */  lw        $k1, 0x118($a1)
/* 464E8 8006B0E8 3369FF00 */  andi      $t1, $k1, 0xff00
/* 464EC 8006B0EC 1120000D */  beqz      $t1, .L8006B124
/* 464F0 8006B0F0 00000000 */   nop      
/* 464F4 8006B0F4 3C088009 */  lui       $t0, 0x8009
/* 464F8 8006B0F8 25085900 */  addiu     $t0, $t0, 0x5900
/* 464FC 8006B0FC 8D080000 */  lw        $t0, ($t0)
/* 46500 8006B100 2401FFFF */  addiu     $at, $zero, -1
/* 46504 8006B104 01014026 */  xor       $t0, $t0, $at
/* 46508 8006B108 3108FF00 */  andi      $t0, $t0, 0xff00
/* 4650C 8006B10C 01284825 */  or        $t1, $t1, $t0
/* 46510 8006B110 3C01FFFF */  lui       $at, 0xffff
/* 46514 8006B114 342100FF */  ori       $at, $at, 0xff
/* 46518 8006B118 0361D824 */  and       $k1, $k1, $at
/* 4651C 8006B11C 0369D825 */  or        $k1, $k1, $t1
/* 46520 8006B120 ACBB0118 */  sw        $k1, 0x118($a1)
.L8006B124:
/* 46524 8006B124 3C1BA430 */  lui       $k1, 0xa430
/* 46528 8006B128 8F7B000C */  lw        $k1, 0xc($k1)
/* 4652C 8006B12C 1360000B */  beqz      $k1, .L8006B15C
/* 46530 8006B130 00000000 */   nop      
/* 46534 8006B134 3C1A8009 */  lui       $k0, 0x8009
/* 46538 8006B138 275A5900 */  addiu     $k0, $k0, 0x5900
/* 4653C 8006B13C 8F5A0000 */  lw        $k0, ($k0)
/* 46540 8006B140 001AD402 */  srl       $k0, $k0, 0x10
/* 46544 8006B144 2401FFFF */  addiu     $at, $zero, -1
/* 46548 8006B148 0341D026 */  xor       $k0, $k0, $at
/* 4654C 8006B14C 335A003F */  andi      $k0, $k0, 0x3f
/* 46550 8006B150 8CA80128 */  lw        $t0, 0x128($a1)
/* 46554 8006B154 0348D024 */  and       $k0, $k0, $t0
/* 46558 8006B158 037AD825 */  or        $k1, $k1, $k0
.L8006B15C:
/* 4655C 8006B15C 10800003 */  beqz      $a0, noEnqueue
/* 46560 8006B160 ACBB0128 */   sw       $k1, 0x128($a1)
/* 46564 8006B164 0C01AC5D */  jal       osEnqueueThread
/* 46568 8006B168 00000000 */   nop      
