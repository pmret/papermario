.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8009A040
.byte 0x00, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08

.section .text

glabel func_8006E310
/* 49710 8006E310 00E0482D */  daddu     $t1, $a3, $zero
/* 49714 8006E314 00C0402D */  daddu     $t0, $a2, $zero
/* 49718 8006E318 150000DF */  bnez      $t0, .L8006E698
/* 4971C 8006E31C 00A0582D */   daddu    $t3, $a1, $zero
/* 49720 8006E320 0089102B */  sltu      $v0, $a0, $t1
/* 49724 8006E324 1040004E */  beqz      $v0, .L8006E460
/* 49728 8006E328 3402FFFF */   ori      $v0, $zero, 0xffff
/* 4972C 8006E32C 0049102B */  sltu      $v0, $v0, $t1
/* 49730 8006E330 14400005 */  bnez      $v0, .L8006E348
/* 49734 8006E334 00E0302D */   daddu    $a2, $a3, $zero
/* 49738 8006E338 2D220100 */  sltiu     $v0, $t1, 0x100
/* 4973C 8006E33C 38420001 */  xori      $v0, $v0, 1
/* 49740 8006E340 0801B8D8 */  j         .L8006E360
/* 49744 8006E344 000218C0 */   sll      $v1, $v0, 3
.L8006E348:
/* 49748 8006E348 3C0200FF */  lui       $v0, 0xff
/* 4974C 8006E34C 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49750 8006E350 0049102B */  sltu      $v0, $v0, $t1
/* 49754 8006E354 14400002 */  bnez      $v0, .L8006E360
/* 49758 8006E358 24030018 */   addiu    $v1, $zero, 0x18
/* 4975C 8006E35C 24030010 */  addiu     $v1, $zero, 0x10
.L8006E360:
/* 49760 8006E360 00661006 */  srlv      $v0, $a2, $v1
/* 49764 8006E364 3C01800A */  lui       $at, %hi(D_8009A040)
/* 49768 8006E368 00220821 */  addu      $at, $at, $v0
/* 4976C 8006E36C 9022A040 */  lbu       $v0, %lo(D_8009A040)($at)
/* 49770 8006E370 24050020 */  addiu     $a1, $zero, 0x20
/* 49774 8006E374 00431021 */  addu      $v0, $v0, $v1
/* 49778 8006E378 00A23023 */  subu      $a2, $a1, $v0
/* 4977C 8006E37C 10C00006 */  beqz      $a2, .L8006E398
/* 49780 8006E380 00C41804 */   sllv     $v1, $a0, $a2
/* 49784 8006E384 00C94804 */  sllv      $t1, $t1, $a2
/* 49788 8006E388 00A61023 */  subu      $v0, $a1, $a2
/* 4978C 8006E38C 004B1006 */  srlv      $v0, $t3, $v0
/* 49790 8006E390 00622025 */  or        $a0, $v1, $v0
/* 49794 8006E394 00CB5804 */  sllv      $t3, $t3, $a2
.L8006E398:
/* 49798 8006E398 00093402 */  srl       $a2, $t1, 0x10
/* 4979C 8006E39C 14C00002 */  bnez      $a2, .L8006E3A8
/* 497A0 8006E3A0 0086001B */   divu     $zero, $a0, $a2
/* 497A4 8006E3A4 0007000D */  break     7
.L8006E3A8:
/* 497A8 8006E3A8 00003812 */   mflo     $a3
/* 497AC 8006E3AC 00001810 */  mfhi      $v1
/* 497B0 8006E3B0 3128FFFF */  andi      $t0, $t1, 0xffff
/* 497B4 8006E3B4 00000000 */  nop
/* 497B8 8006E3B8 00E80018 */  mult      $a3, $t0
/* 497BC 8006E3BC 000B1402 */  srl       $v0, $t3, 0x10
/* 497C0 8006E3C0 00031C00 */  sll       $v1, $v1, 0x10
/* 497C4 8006E3C4 00621825 */  or        $v1, $v1, $v0
/* 497C8 8006E3C8 00002812 */  mflo      $a1
/* 497CC 8006E3CC 0065102B */  sltu      $v0, $v1, $a1
/* 497D0 8006E3D0 5040000B */  beql      $v0, $zero, .L8006E400
/* 497D4 8006E3D4 00651823 */   subu     $v1, $v1, $a1
/* 497D8 8006E3D8 00691821 */  addu      $v1, $v1, $t1
/* 497DC 8006E3DC 0069102B */  sltu      $v0, $v1, $t1
/* 497E0 8006E3E0 14400006 */  bnez      $v0, .L8006E3FC
/* 497E4 8006E3E4 24E7FFFF */   addiu    $a3, $a3, -1
/* 497E8 8006E3E8 0065102B */  sltu      $v0, $v1, $a1
/* 497EC 8006E3EC 50400004 */  beql      $v0, $zero, .L8006E400
/* 497F0 8006E3F0 00651823 */   subu     $v1, $v1, $a1
/* 497F4 8006E3F4 24E7FFFF */  addiu     $a3, $a3, -1
/* 497F8 8006E3F8 00691821 */  addu      $v1, $v1, $t1
.L8006E3FC:
/* 497FC 8006E3FC 00651823 */  subu      $v1, $v1, $a1
.L8006E400:
/* 49800 8006E400 14C00002 */  bnez      $a2, .L8006E40C
/* 49804 8006E404 0066001B */   divu     $zero, $v1, $a2
/* 49808 8006E408 0007000D */  break     7
.L8006E40C:
/* 4980C 8006E40C 00002012 */   mflo     $a0
/* 49810 8006E410 00001810 */  mfhi      $v1
/* 49814 8006E414 00000000 */  nop
/* 49818 8006E418 00000000 */  nop
/* 4981C 8006E41C 00880018 */  mult      $a0, $t0
/* 49820 8006E420 3162FFFF */  andi      $v0, $t3, 0xffff
/* 49824 8006E424 00031C00 */  sll       $v1, $v1, 0x10
/* 49828 8006E428 00621825 */  or        $v1, $v1, $v0
/* 4982C 8006E42C 00002812 */  mflo      $a1
/* 49830 8006E430 0065102B */  sltu      $v0, $v1, $a1
/* 49834 8006E434 10400007 */  beqz      $v0, .L8006E454
/* 49838 8006E438 00691821 */   addu     $v1, $v1, $t1
/* 4983C 8006E43C 0069102B */  sltu      $v0, $v1, $t1
/* 49840 8006E440 14400004 */  bnez      $v0, .L8006E454
/* 49844 8006E444 2484FFFF */   addiu    $a0, $a0, -1
/* 49848 8006E448 0065102B */  sltu      $v0, $v1, $a1
/* 4984C 8006E44C 54400001 */  bnel      $v0, $zero, .L8006E454
/* 49850 8006E450 2484FFFF */   addiu    $a0, $a0, -1
.L8006E454:
/* 49854 8006E454 00071400 */  sll       $v0, $a3, 0x10
/* 49858 8006E458 0801BA13 */  j         .L8006E84C
/* 4985C 8006E45C 00443025 */   or       $a2, $v0, $a0
.L8006E460:
/* 49860 8006E460 15200008 */  bnez      $t1, .L8006E484
/* 49864 8006E464 0049102B */   sltu     $v0, $v0, $t1
/* 49868 8006E468 24020001 */  addiu     $v0, $zero, 1
/* 4986C 8006E46C 15000002 */  bnez      $t0, .L8006E478
/* 49870 8006E470 0048001B */   divu     $zero, $v0, $t0
/* 49874 8006E474 0007000D */  break     7
.L8006E478:
/* 49878 8006E478 00004812 */   mflo     $t1
/* 4987C 8006E47C 3402FFFF */  ori       $v0, $zero, 0xffff
/* 49880 8006E480 0049102B */  sltu      $v0, $v0, $t1
.L8006E484:
/* 49884 8006E484 14400005 */  bnez      $v0, .L8006E49C
/* 49888 8006E488 0120282D */   daddu    $a1, $t1, $zero
/* 4988C 8006E48C 2D220100 */  sltiu     $v0, $t1, 0x100
/* 49890 8006E490 38420001 */  xori      $v0, $v0, 1
/* 49894 8006E494 0801B92D */  j         .L8006E4B4
/* 49898 8006E498 000218C0 */   sll      $v1, $v0, 3
.L8006E49C:
/* 4989C 8006E49C 3C0200FF */  lui       $v0, 0xff
/* 498A0 8006E4A0 3442FFFF */  ori       $v0, $v0, 0xffff
/* 498A4 8006E4A4 0049102B */  sltu      $v0, $v0, $t1
/* 498A8 8006E4A8 14400002 */  bnez      $v0, .L8006E4B4
/* 498AC 8006E4AC 24030018 */   addiu    $v1, $zero, 0x18
/* 498B0 8006E4B0 24030010 */  addiu     $v1, $zero, 0x10
.L8006E4B4:
/* 498B4 8006E4B4 00651006 */  srlv      $v0, $a1, $v1
/* 498B8 8006E4B8 3C01800A */  lui       $at, %hi(D_8009A040)
/* 498BC 8006E4BC 00220821 */  addu      $at, $at, $v0
/* 498C0 8006E4C0 9022A040 */  lbu       $v0, %lo(D_8009A040)($at)
/* 498C4 8006E4C4 00431021 */  addu      $v0, $v0, $v1
/* 498C8 8006E4C8 24030020 */  addiu     $v1, $zero, 0x20
/* 498CC 8006E4CC 00623023 */  subu      $a2, $v1, $v0
/* 498D0 8006E4D0 14C00004 */  bnez      $a2, .L8006E4E4
/* 498D4 8006E4D4 00662823 */   subu     $a1, $v1, $a2
/* 498D8 8006E4D8 00892023 */  subu      $a0, $a0, $t1
/* 498DC 8006E4DC 0801B974 */  j         .L8006E5D0
/* 498E0 8006E4E0 240A0001 */   addiu    $t2, $zero, 1
.L8006E4E4:
/* 498E4 8006E4E4 00C94804 */  sllv      $t1, $t1, $a2
/* 498E8 8006E4E8 00A43806 */  srlv      $a3, $a0, $a1
/* 498EC 8006E4EC 00C41804 */  sllv      $v1, $a0, $a2
/* 498F0 8006E4F0 00AB1006 */  srlv      $v0, $t3, $a1
/* 498F4 8006E4F4 00622025 */  or        $a0, $v1, $v0
/* 498F8 8006E4F8 00CB5804 */  sllv      $t3, $t3, $a2
/* 498FC 8006E4FC 00093402 */  srl       $a2, $t1, 0x10
/* 49900 8006E500 14C00002 */  bnez      $a2, .L8006E50C
/* 49904 8006E504 00E6001B */   divu     $zero, $a3, $a2
/* 49908 8006E508 0007000D */  break     7
.L8006E50C:
/* 4990C 8006E50C 00004012 */   mflo     $t0
/* 49910 8006E510 00001810 */  mfhi      $v1
/* 49914 8006E514 3125FFFF */  andi      $a1, $t1, 0xffff
/* 49918 8006E518 00000000 */  nop
/* 4991C 8006E51C 01050018 */  mult      $t0, $a1
/* 49920 8006E520 00041402 */  srl       $v0, $a0, 0x10
/* 49924 8006E524 00031C00 */  sll       $v1, $v1, 0x10
/* 49928 8006E528 00621825 */  or        $v1, $v1, $v0
/* 4992C 8006E52C 00003812 */  mflo      $a3
/* 49930 8006E530 0067102B */  sltu      $v0, $v1, $a3
/* 49934 8006E534 5040000B */  beql      $v0, $zero, .L8006E564
/* 49938 8006E538 00671823 */   subu     $v1, $v1, $a3
/* 4993C 8006E53C 00691821 */  addu      $v1, $v1, $t1
/* 49940 8006E540 0069102B */  sltu      $v0, $v1, $t1
/* 49944 8006E544 14400006 */  bnez      $v0, .L8006E560
/* 49948 8006E548 2508FFFF */   addiu    $t0, $t0, -1
/* 4994C 8006E54C 0067102B */  sltu      $v0, $v1, $a3
/* 49950 8006E550 50400004 */  beql      $v0, $zero, .L8006E564
/* 49954 8006E554 00671823 */   subu     $v1, $v1, $a3
/* 49958 8006E558 2508FFFF */  addiu     $t0, $t0, -1
/* 4995C 8006E55C 00691821 */  addu      $v1, $v1, $t1
.L8006E560:
/* 49960 8006E560 00671823 */  subu      $v1, $v1, $a3
.L8006E564:
/* 49964 8006E564 14C00002 */  bnez      $a2, .L8006E570
/* 49968 8006E568 0066001B */   divu     $zero, $v1, $a2
/* 4996C 8006E56C 0007000D */  break     7
.L8006E570:
/* 49970 8006E570 00003012 */   mflo     $a2
/* 49974 8006E574 00001810 */  mfhi      $v1
/* 49978 8006E578 00000000 */  nop
/* 4997C 8006E57C 00000000 */  nop
/* 49980 8006E580 00C50018 */  mult      $a2, $a1
/* 49984 8006E584 3082FFFF */  andi      $v0, $a0, 0xffff
/* 49988 8006E588 00031C00 */  sll       $v1, $v1, 0x10
/* 4998C 8006E58C 00621825 */  or        $v1, $v1, $v0
/* 49990 8006E590 00003812 */  mflo      $a3
/* 49994 8006E594 0067102B */  sltu      $v0, $v1, $a3
/* 49998 8006E598 1040000B */  beqz      $v0, .L8006E5C8
/* 4999C 8006E59C 00081400 */   sll      $v0, $t0, 0x10
/* 499A0 8006E5A0 00691821 */  addu      $v1, $v1, $t1
/* 499A4 8006E5A4 0069102B */  sltu      $v0, $v1, $t1
/* 499A8 8006E5A8 14400006 */  bnez      $v0, .L8006E5C4
/* 499AC 8006E5AC 24C6FFFF */   addiu    $a2, $a2, -1
/* 499B0 8006E5B0 0067102B */  sltu      $v0, $v1, $a3
/* 499B4 8006E5B4 10400004 */  beqz      $v0, .L8006E5C8
/* 499B8 8006E5B8 00081400 */   sll      $v0, $t0, 0x10
/* 499BC 8006E5BC 24C6FFFF */  addiu     $a2, $a2, -1
/* 499C0 8006E5C0 00691821 */  addu      $v1, $v1, $t1
.L8006E5C4:
/* 499C4 8006E5C4 00081400 */  sll       $v0, $t0, 0x10
.L8006E5C8:
/* 499C8 8006E5C8 00465025 */  or        $t2, $v0, $a2
/* 499CC 8006E5CC 00672023 */  subu      $a0, $v1, $a3
.L8006E5D0:
/* 499D0 8006E5D0 00093402 */  srl       $a2, $t1, 0x10
/* 499D4 8006E5D4 14C00002 */  bnez      $a2, .L8006E5E0
/* 499D8 8006E5D8 0086001B */   divu     $zero, $a0, $a2
/* 499DC 8006E5DC 0007000D */  break     7
.L8006E5E0:
/* 499E0 8006E5E0 00003812 */   mflo     $a3
/* 499E4 8006E5E4 00001810 */  mfhi      $v1
/* 499E8 8006E5E8 3128FFFF */  andi      $t0, $t1, 0xffff
/* 499EC 8006E5EC 00000000 */  nop
/* 499F0 8006E5F0 00E80018 */  mult      $a3, $t0
/* 499F4 8006E5F4 000B1402 */  srl       $v0, $t3, 0x10
/* 499F8 8006E5F8 00031C00 */  sll       $v1, $v1, 0x10
/* 499FC 8006E5FC 00621825 */  or        $v1, $v1, $v0
/* 49A00 8006E600 00002812 */  mflo      $a1
/* 49A04 8006E604 0065102B */  sltu      $v0, $v1, $a1
/* 49A08 8006E608 5040000B */  beql      $v0, $zero, .L8006E638
/* 49A0C 8006E60C 00651823 */   subu     $v1, $v1, $a1
/* 49A10 8006E610 00691821 */  addu      $v1, $v1, $t1
/* 49A14 8006E614 0069102B */  sltu      $v0, $v1, $t1
/* 49A18 8006E618 14400006 */  bnez      $v0, .L8006E634
/* 49A1C 8006E61C 24E7FFFF */   addiu    $a3, $a3, -1
/* 49A20 8006E620 0065102B */  sltu      $v0, $v1, $a1
/* 49A24 8006E624 50400004 */  beql      $v0, $zero, .L8006E638
/* 49A28 8006E628 00651823 */   subu     $v1, $v1, $a1
/* 49A2C 8006E62C 24E7FFFF */  addiu     $a3, $a3, -1
/* 49A30 8006E630 00691821 */  addu      $v1, $v1, $t1
.L8006E634:
/* 49A34 8006E634 00651823 */  subu      $v1, $v1, $a1
.L8006E638:
/* 49A38 8006E638 14C00002 */  bnez      $a2, .L8006E644
/* 49A3C 8006E63C 0066001B */   divu     $zero, $v1, $a2
/* 49A40 8006E640 0007000D */  break     7
.L8006E644:
/* 49A44 8006E644 00002012 */   mflo     $a0
/* 49A48 8006E648 00001810 */  mfhi      $v1
/* 49A4C 8006E64C 00000000 */  nop
/* 49A50 8006E650 00000000 */  nop
/* 49A54 8006E654 00880018 */  mult      $a0, $t0
/* 49A58 8006E658 3162FFFF */  andi      $v0, $t3, 0xffff
/* 49A5C 8006E65C 00031C00 */  sll       $v1, $v1, 0x10
/* 49A60 8006E660 00621825 */  or        $v1, $v1, $v0
/* 49A64 8006E664 00002812 */  mflo      $a1
/* 49A68 8006E668 0065102B */  sltu      $v0, $v1, $a1
/* 49A6C 8006E66C 10400007 */  beqz      $v0, .L8006E68C
/* 49A70 8006E670 00691821 */   addu     $v1, $v1, $t1
/* 49A74 8006E674 0069102B */  sltu      $v0, $v1, $t1
/* 49A78 8006E678 14400004 */  bnez      $v0, .L8006E68C
/* 49A7C 8006E67C 2484FFFF */   addiu    $a0, $a0, -1
/* 49A80 8006E680 0065102B */  sltu      $v0, $v1, $a1
/* 49A84 8006E684 54400001 */  bnel      $v0, $zero, .L8006E68C
/* 49A88 8006E688 2484FFFF */   addiu    $a0, $a0, -1
.L8006E68C:
/* 49A8C 8006E68C 00071400 */  sll       $v0, $a3, 0x10
/* 49A90 8006E690 0801BA14 */  j         .L8006E850
/* 49A94 8006E694 00443025 */   or       $a2, $v0, $a0
.L8006E698:
/* 49A98 8006E698 0088102B */  sltu      $v0, $a0, $t0
/* 49A9C 8006E69C 10400003 */  beqz      $v0, .L8006E6AC
/* 49AA0 8006E6A0 3402FFFF */   ori      $v0, $zero, 0xffff
/* 49AA4 8006E6A4 0801BA13 */  j         .L8006E84C
/* 49AA8 8006E6A8 0000302D */   daddu    $a2, $zero, $zero
.L8006E6AC:
/* 49AAC 8006E6AC 0048102B */  sltu      $v0, $v0, $t0
/* 49AB0 8006E6B0 14400005 */  bnez      $v0, .L8006E6C8
/* 49AB4 8006E6B4 0100282D */   daddu    $a1, $t0, $zero
/* 49AB8 8006E6B8 2D020100 */  sltiu     $v0, $t0, 0x100
/* 49ABC 8006E6BC 38420001 */  xori      $v0, $v0, 1
/* 49AC0 8006E6C0 0801B9B8 */  j         .L8006E6E0
/* 49AC4 8006E6C4 000218C0 */   sll      $v1, $v0, 3
.L8006E6C8:
/* 49AC8 8006E6C8 3C0200FF */  lui       $v0, 0xff
/* 49ACC 8006E6CC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49AD0 8006E6D0 0048102B */  sltu      $v0, $v0, $t0
/* 49AD4 8006E6D4 14400002 */  bnez      $v0, .L8006E6E0
/* 49AD8 8006E6D8 24030018 */   addiu    $v1, $zero, 0x18
/* 49ADC 8006E6DC 24030010 */  addiu     $v1, $zero, 0x10
.L8006E6E0:
/* 49AE0 8006E6E0 00651006 */  srlv      $v0, $a1, $v1
/* 49AE4 8006E6E4 3C01800A */  lui       $at, %hi(D_8009A040)
/* 49AE8 8006E6E8 00220821 */  addu      $at, $at, $v0
/* 49AEC 8006E6EC 9022A040 */  lbu       $v0, %lo(D_8009A040)($at)
/* 49AF0 8006E6F0 00431021 */  addu      $v0, $v0, $v1
/* 49AF4 8006E6F4 24030020 */  addiu     $v1, $zero, 0x20
/* 49AF8 8006E6F8 00623023 */  subu      $a2, $v1, $v0
/* 49AFC 8006E6FC 54C00009 */  bnel      $a2, $zero, .L8006E724
/* 49B00 8006E700 00662823 */   subu     $a1, $v1, $a2
/* 49B04 8006E704 0104102B */  sltu      $v0, $t0, $a0
/* 49B08 8006E708 14400050 */  bnez      $v0, .L8006E84C
/* 49B0C 8006E70C 24060001 */   addiu    $a2, $zero, 1
/* 49B10 8006E710 0169102B */  sltu      $v0, $t3, $t1
/* 49B14 8006E714 1440004D */  bnez      $v0, .L8006E84C
/* 49B18 8006E718 0000302D */   daddu    $a2, $zero, $zero
/* 49B1C 8006E71C 0801BA13 */  j         .L8006E84C
/* 49B20 8006E720 24060001 */   addiu    $a2, $zero, 1
.L8006E724:
/* 49B24 8006E724 00C81804 */  sllv      $v1, $t0, $a2
/* 49B28 8006E728 00A91006 */  srlv      $v0, $t1, $a1
/* 49B2C 8006E72C 00624025 */  or        $t0, $v1, $v0
/* 49B30 8006E730 00C94804 */  sllv      $t1, $t1, $a2
/* 49B34 8006E734 00A43806 */  srlv      $a3, $a0, $a1
/* 49B38 8006E738 00C41804 */  sllv      $v1, $a0, $a2
/* 49B3C 8006E73C 00AB1006 */  srlv      $v0, $t3, $a1
/* 49B40 8006E740 00622025 */  or        $a0, $v1, $v0
/* 49B44 8006E744 00CB5804 */  sllv      $t3, $t3, $a2
/* 49B48 8006E748 00083402 */  srl       $a2, $t0, 0x10
/* 49B4C 8006E74C 14C00002 */  bnez      $a2, .L8006E758
/* 49B50 8006E750 00E6001B */   divu     $zero, $a3, $a2
/* 49B54 8006E754 0007000D */  break     7
.L8006E758:
/* 49B58 8006E758 00005012 */   mflo     $t2
/* 49B5C 8006E75C 00001810 */  mfhi      $v1
/* 49B60 8006E760 3105FFFF */  andi      $a1, $t0, 0xffff
/* 49B64 8006E764 00000000 */  nop
/* 49B68 8006E768 01450018 */  mult      $t2, $a1
/* 49B6C 8006E76C 00041402 */  srl       $v0, $a0, 0x10
/* 49B70 8006E770 00031C00 */  sll       $v1, $v1, 0x10
/* 49B74 8006E774 00621825 */  or        $v1, $v1, $v0
/* 49B78 8006E778 00003812 */  mflo      $a3
/* 49B7C 8006E77C 0067102B */  sltu      $v0, $v1, $a3
/* 49B80 8006E780 5040000B */  beql      $v0, $zero, .L8006E7B0
/* 49B84 8006E784 00671823 */   subu     $v1, $v1, $a3
/* 49B88 8006E788 00681821 */  addu      $v1, $v1, $t0
/* 49B8C 8006E78C 0068102B */  sltu      $v0, $v1, $t0
/* 49B90 8006E790 14400006 */  bnez      $v0, .L8006E7AC
/* 49B94 8006E794 254AFFFF */   addiu    $t2, $t2, -1
/* 49B98 8006E798 0067102B */  sltu      $v0, $v1, $a3
/* 49B9C 8006E79C 50400004 */  beql      $v0, $zero, .L8006E7B0
/* 49BA0 8006E7A0 00671823 */   subu     $v1, $v1, $a3
/* 49BA4 8006E7A4 254AFFFF */  addiu     $t2, $t2, -1
/* 49BA8 8006E7A8 00681821 */  addu      $v1, $v1, $t0
.L8006E7AC:
/* 49BAC 8006E7AC 00671823 */  subu      $v1, $v1, $a3
.L8006E7B0:
/* 49BB0 8006E7B0 14C00002 */  bnez      $a2, .L8006E7BC
/* 49BB4 8006E7B4 0066001B */   divu     $zero, $v1, $a2
/* 49BB8 8006E7B8 0007000D */  break     7
.L8006E7BC:
/* 49BBC 8006E7BC 00003012 */   mflo     $a2
/* 49BC0 8006E7C0 00001810 */  mfhi      $v1
/* 49BC4 8006E7C4 00000000 */  nop
/* 49BC8 8006E7C8 00000000 */  nop
/* 49BCC 8006E7CC 00C50018 */  mult      $a2, $a1
/* 49BD0 8006E7D0 3082FFFF */  andi      $v0, $a0, 0xffff
/* 49BD4 8006E7D4 00031C00 */  sll       $v1, $v1, 0x10
/* 49BD8 8006E7D8 00621825 */  or        $v1, $v1, $v0
/* 49BDC 8006E7DC 00003812 */  mflo      $a3
/* 49BE0 8006E7E0 0067102B */  sltu      $v0, $v1, $a3
/* 49BE4 8006E7E4 1040000B */  beqz      $v0, .L8006E814
/* 49BE8 8006E7E8 000A1400 */   sll      $v0, $t2, 0x10
/* 49BEC 8006E7EC 00681821 */  addu      $v1, $v1, $t0
/* 49BF0 8006E7F0 0068102B */  sltu      $v0, $v1, $t0
/* 49BF4 8006E7F4 14400006 */  bnez      $v0, .L8006E810
/* 49BF8 8006E7F8 24C6FFFF */   addiu    $a2, $a2, -1
/* 49BFC 8006E7FC 0067102B */  sltu      $v0, $v1, $a3
/* 49C00 8006E800 10400004 */  beqz      $v0, .L8006E814
/* 49C04 8006E804 000A1400 */   sll      $v0, $t2, 0x10
/* 49C08 8006E808 24C6FFFF */  addiu     $a2, $a2, -1
/* 49C0C 8006E80C 00681821 */  addu      $v1, $v1, $t0
.L8006E810:
/* 49C10 8006E810 000A1400 */  sll       $v0, $t2, 0x10
.L8006E814:
/* 49C14 8006E814 00463025 */  or        $a2, $v0, $a2
/* 49C18 8006E818 00672023 */  subu      $a0, $v1, $a3
/* 49C1C 8006E81C 00C90019 */  multu     $a2, $t1
/* 49C20 8006E820 00001810 */  mfhi      $v1
/* 49C24 8006E824 0083102B */  sltu      $v0, $a0, $v1
/* 49C28 8006E828 00004012 */  mflo      $t0
/* 49C2C 8006E82C 54400007 */  bnel      $v0, $zero, .L8006E84C
/* 49C30 8006E830 24C6FFFF */   addiu    $a2, $a2, -1
/* 49C34 8006E834 14640006 */  bne       $v1, $a0, .L8006E850
/* 49C38 8006E838 0000502D */   daddu    $t2, $zero, $zero
/* 49C3C 8006E83C 0168102B */  sltu      $v0, $t3, $t0
/* 49C40 8006E840 10400004 */  beqz      $v0, .L8006E854
/* 49C44 8006E844 00C0682D */   daddu    $t5, $a2, $zero
/* 49C48 8006E848 24C6FFFF */  addiu     $a2, $a2, -1
.L8006E84C:
/* 49C4C 8006E84C 0000502D */  daddu     $t2, $zero, $zero
.L8006E850:
/* 49C50 8006E850 00C0682D */  daddu     $t5, $a2, $zero
.L8006E854:
/* 49C54 8006E854 0140602D */  daddu     $t4, $t2, $zero
/* 49C58 8006E858 0180102D */  daddu     $v0, $t4, $zero
/* 49C5C 8006E85C 03E00008 */  jr        $ra
/* 49C60 8006E860 01A0182D */   daddu    $v1, $t5, $zero
/* 49C64 8006E864 00000000 */  nop
/* 49C68 8006E868 00000000 */  nop
/* 49C6C 8006E86C 00000000 */  nop
