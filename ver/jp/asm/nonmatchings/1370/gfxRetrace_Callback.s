.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel gfxRetrace_Callback
/* 1440 80026040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1444 80026044 AFB10014 */  sw        $s1, 0x14($sp)
/* 1448 80026048 3C118007 */  lui       $s1, %hi(D_80073DE0)
/* 144C 8002604C 26313DE0 */  addiu     $s1, $s1, %lo(D_80073DE0)
/* 1450 80026050 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1454 80026054 AFB00010 */  sw        $s0, 0x10($sp)
/* 1458 80026058 8E230000 */  lw        $v1, ($s1)
/* 145C 8002605C 10600022 */  beqz      $v1, .L800260E8
/* 1460 80026060 0080802D */   daddu    $s0, $a0, $zero
/* 1464 80026064 24020001 */  addiu     $v0, $zero, 1
/* 1468 80026068 14620016 */  bne       $v1, $v0, .L800260C4
/* 146C 8002606C 00000000 */   nop
/* 1470 80026070 0C017BE0 */  jal       func_8005EF80
/* 1474 80026074 00000000 */   nop
/* 1478 80026078 16000012 */  bnez      $s0, .L800260C4
/* 147C 8002607C 00000000 */   nop
/* 1480 80026080 0C019A60 */  jal       func_80066980
/* 1484 80026084 00000000 */   nop
/* 1488 80026088 3C10800A */  lui       $s0, %hi(D_8009A660)
/* 148C 8002608C 2610A660 */  addiu     $s0, $s0, %lo(D_8009A660)
/* 1490 80026090 0200202D */  daddu     $a0, $s0, $zero
/* 1494 80026094 AE020008 */  sw        $v0, 8($s0)
/* 1498 80026098 AE020004 */  sw        $v0, 4($s0)
/* 149C 8002609C AE020000 */  sw        $v0, ($s0)
/* 14A0 800260A0 3C018007 */  lui       $at, %hi(D_80073DE4)
/* 14A4 800260A4 AC223DE4 */  sw        $v0, %lo(D_80073DE4)($at)
/* 14A8 800260A8 0C017BE8 */  jal       func_8005EFA0
/* 14AC 800260AC 24050003 */   addiu    $a1, $zero, 3
/* 14B0 800260B0 8E040000 */  lw        $a0, ($s0)
/* 14B4 800260B4 0C019BFC */  jal       func_80066FF0
/* 14B8 800260B8 00000000 */   nop
/* 14BC 800260BC 24020002 */  addiu     $v0, $zero, 2
/* 14C0 800260C0 AE220000 */  sw        $v0, ($s1)
.L800260C4:
/* 14C4 800260C4 3C038007 */  lui       $v1, %hi(D_80073DE0)
/* 14C8 800260C8 8C633DE0 */  lw        $v1, %lo(D_80073DE0)($v1)
/* 14CC 800260CC 24020002 */  addiu     $v0, $zero, 2
/* 14D0 800260D0 14620018 */  bne       $v1, $v0, .L80026134
/* 14D4 800260D4 00000000 */   nop
/* 14D8 800260D8 0C009852 */  jal       func_80026148
/* 14DC 800260DC 00000000 */   nop
/* 14E0 800260E0 0800984D */  j         .L80026134
/* 14E4 800260E4 00000000 */   nop
.L800260E8:
/* 14E8 800260E8 3C038007 */  lui       $v1, %hi(D_80073DEA)
/* 14EC 800260EC 24633DEA */  addiu     $v1, $v1, %lo(D_80073DEA)
/* 14F0 800260F0 94620000 */  lhu       $v0, ($v1)
/* 14F4 800260F4 38420001 */  xori      $v0, $v0, 1
/* 14F8 800260F8 1440000E */  bnez      $v0, .L80026134
/* 14FC 800260FC A4620000 */   sh       $v0, ($v1)
/* 1500 80026100 0C0099C4 */  jal       func_80026710
/* 1504 80026104 00000000 */   nop
/* 1508 80026108 3C038007 */  lui       $v1, %hi(D_80073DE8)
/* 150C 8002610C 24633DE8 */  addiu     $v1, $v1, %lo(D_80073DE8)
/* 1510 80026110 24020001 */  addiu     $v0, $zero, 1
/* 1514 80026114 A4620000 */  sh        $v0, ($v1)
/* 1518 80026118 2A020003 */  slti      $v0, $s0, 3
/* 151C 8002611C 10400005 */  beqz      $v0, .L80026134
/* 1520 80026120 00000000 */   nop
/* 1524 80026124 0C009A70 */  jal       func_800269C0
/* 1528 80026128 A4600000 */   sh       $zero, ($v1)
/* 152C 8002612C 0C009AB5 */  jal       func_80026AD4
/* 1530 80026130 00000000 */   nop
.L80026134:
/* 1534 80026134 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1538 80026138 8FB10014 */  lw        $s1, 0x14($sp)
/* 153C 8002613C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1540 80026140 03E00008 */  jr        $ra
/* 1544 80026144 27BD0020 */   addiu    $sp, $sp, 0x20
