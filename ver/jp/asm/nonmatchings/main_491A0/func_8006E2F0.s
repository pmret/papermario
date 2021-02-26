.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006E2F0
/* 496F0 8006E2F0 00E0482D */  daddu     $t1, $a3, $zero
/* 496F4 8006E2F4 00C0402D */  daddu     $t0, $a2, $zero
/* 496F8 8006E2F8 150000DF */  bnez      $t0, .L8006E678
/* 496FC 8006E2FC 00A0582D */   daddu    $t3, $a1, $zero
/* 49700 8006E300 0089102B */  sltu      $v0, $a0, $t1
/* 49704 8006E304 1040004E */  beqz      $v0, .L8006E440
/* 49708 8006E308 3402FFFF */   ori      $v0, $zero, 0xffff
/* 4970C 8006E30C 0049102B */  sltu      $v0, $v0, $t1
/* 49710 8006E310 14400005 */  bnez      $v0, .L8006E328
/* 49714 8006E314 00E0302D */   daddu    $a2, $a3, $zero
/* 49718 8006E318 2D220100 */  sltiu     $v0, $t1, 0x100
/* 4971C 8006E31C 38420001 */  xori      $v0, $v0, 1
/* 49720 8006E320 0801B8D0 */  j         .L8006E340
/* 49724 8006E324 000218C0 */   sll      $v1, $v0, 3
.L8006E328:
/* 49728 8006E328 3C0200FF */  lui       $v0, 0xff
/* 4972C 8006E32C 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49730 8006E330 0049102B */  sltu      $v0, $v0, $t1
/* 49734 8006E334 14400002 */  bnez      $v0, .L8006E340
/* 49738 8006E338 24030018 */   addiu    $v1, $zero, 0x18
/* 4973C 8006E33C 24030010 */  addiu     $v1, $zero, 0x10
.L8006E340:
/* 49740 8006E340 00661006 */  srlv      $v0, $a2, $v1
/* 49744 8006E344 3C01800A */  lui       $at, %hi(D_8009A020)
/* 49748 8006E348 00220821 */  addu      $at, $at, $v0
/* 4974C 8006E34C 9022A020 */  lbu       $v0, %lo(D_8009A020)($at)
/* 49750 8006E350 24050020 */  addiu     $a1, $zero, 0x20
/* 49754 8006E354 00431021 */  addu      $v0, $v0, $v1
/* 49758 8006E358 00A23023 */  subu      $a2, $a1, $v0
/* 4975C 8006E35C 10C00006 */  beqz      $a2, .L8006E378
/* 49760 8006E360 00C41804 */   sllv     $v1, $a0, $a2
/* 49764 8006E364 00C94804 */  sllv      $t1, $t1, $a2
/* 49768 8006E368 00A61023 */  subu      $v0, $a1, $a2
/* 4976C 8006E36C 004B1006 */  srlv      $v0, $t3, $v0
/* 49770 8006E370 00622025 */  or        $a0, $v1, $v0
/* 49774 8006E374 00CB5804 */  sllv      $t3, $t3, $a2
.L8006E378:
/* 49778 8006E378 00093402 */  srl       $a2, $t1, 0x10
/* 4977C 8006E37C 14C00002 */  bnez      $a2, .L8006E388
/* 49780 8006E380 0086001B */   divu     $zero, $a0, $a2
/* 49784 8006E384 0007000D */  break     7
.L8006E388:
/* 49788 8006E388 00003812 */   mflo     $a3
/* 4978C 8006E38C 00001810 */  mfhi      $v1
/* 49790 8006E390 3128FFFF */  andi      $t0, $t1, 0xffff
/* 49794 8006E394 00000000 */  nop
/* 49798 8006E398 00E80018 */  mult      $a3, $t0
/* 4979C 8006E39C 000B1402 */  srl       $v0, $t3, 0x10
/* 497A0 8006E3A0 00031C00 */  sll       $v1, $v1, 0x10
/* 497A4 8006E3A4 00621825 */  or        $v1, $v1, $v0
/* 497A8 8006E3A8 00002812 */  mflo      $a1
/* 497AC 8006E3AC 0065102B */  sltu      $v0, $v1, $a1
/* 497B0 8006E3B0 5040000B */  beql      $v0, $zero, .L8006E3E0
/* 497B4 8006E3B4 00651823 */   subu     $v1, $v1, $a1
/* 497B8 8006E3B8 00691821 */  addu      $v1, $v1, $t1
/* 497BC 8006E3BC 0069102B */  sltu      $v0, $v1, $t1
/* 497C0 8006E3C0 14400006 */  bnez      $v0, .L8006E3DC
/* 497C4 8006E3C4 24E7FFFF */   addiu    $a3, $a3, -1
/* 497C8 8006E3C8 0065102B */  sltu      $v0, $v1, $a1
/* 497CC 8006E3CC 50400004 */  beql      $v0, $zero, .L8006E3E0
/* 497D0 8006E3D0 00651823 */   subu     $v1, $v1, $a1
/* 497D4 8006E3D4 24E7FFFF */  addiu     $a3, $a3, -1
/* 497D8 8006E3D8 00691821 */  addu      $v1, $v1, $t1
.L8006E3DC:
/* 497DC 8006E3DC 00651823 */  subu      $v1, $v1, $a1
.L8006E3E0:
/* 497E0 8006E3E0 14C00002 */  bnez      $a2, .L8006E3EC
/* 497E4 8006E3E4 0066001B */   divu     $zero, $v1, $a2
/* 497E8 8006E3E8 0007000D */  break     7
.L8006E3EC:
/* 497EC 8006E3EC 00002012 */   mflo     $a0
/* 497F0 8006E3F0 00001810 */  mfhi      $v1
/* 497F4 8006E3F4 00000000 */  nop
/* 497F8 8006E3F8 00000000 */  nop
/* 497FC 8006E3FC 00880018 */  mult      $a0, $t0
/* 49800 8006E400 3162FFFF */  andi      $v0, $t3, 0xffff
/* 49804 8006E404 00031C00 */  sll       $v1, $v1, 0x10
/* 49808 8006E408 00621825 */  or        $v1, $v1, $v0
/* 4980C 8006E40C 00002812 */  mflo      $a1
/* 49810 8006E410 0065102B */  sltu      $v0, $v1, $a1
/* 49814 8006E414 10400007 */  beqz      $v0, .L8006E434
/* 49818 8006E418 00691821 */   addu     $v1, $v1, $t1
/* 4981C 8006E41C 0069102B */  sltu      $v0, $v1, $t1
/* 49820 8006E420 14400004 */  bnez      $v0, .L8006E434
/* 49824 8006E424 2484FFFF */   addiu    $a0, $a0, -1
/* 49828 8006E428 0065102B */  sltu      $v0, $v1, $a1
/* 4982C 8006E42C 54400001 */  bnel      $v0, $zero, .L8006E434
/* 49830 8006E430 2484FFFF */   addiu    $a0, $a0, -1
.L8006E434:
/* 49834 8006E434 00071400 */  sll       $v0, $a3, 0x10
/* 49838 8006E438 0801BA0B */  j         .L8006E82C
/* 4983C 8006E43C 00443025 */   or       $a2, $v0, $a0
.L8006E440:
/* 49840 8006E440 15200008 */  bnez      $t1, .L8006E464
/* 49844 8006E444 0049102B */   sltu     $v0, $v0, $t1
/* 49848 8006E448 24020001 */  addiu     $v0, $zero, 1
/* 4984C 8006E44C 15000002 */  bnez      $t0, .L8006E458
/* 49850 8006E450 0048001B */   divu     $zero, $v0, $t0
/* 49854 8006E454 0007000D */  break     7
.L8006E458:
/* 49858 8006E458 00004812 */   mflo     $t1
/* 4985C 8006E45C 3402FFFF */  ori       $v0, $zero, 0xffff
/* 49860 8006E460 0049102B */  sltu      $v0, $v0, $t1
.L8006E464:
/* 49864 8006E464 14400005 */  bnez      $v0, .L8006E47C
/* 49868 8006E468 0120282D */   daddu    $a1, $t1, $zero
/* 4986C 8006E46C 2D220100 */  sltiu     $v0, $t1, 0x100
/* 49870 8006E470 38420001 */  xori      $v0, $v0, 1
/* 49874 8006E474 0801B925 */  j         .L8006E494
/* 49878 8006E478 000218C0 */   sll      $v1, $v0, 3
.L8006E47C:
/* 4987C 8006E47C 3C0200FF */  lui       $v0, 0xff
/* 49880 8006E480 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49884 8006E484 0049102B */  sltu      $v0, $v0, $t1
/* 49888 8006E488 14400002 */  bnez      $v0, .L8006E494
/* 4988C 8006E48C 24030018 */   addiu    $v1, $zero, 0x18
/* 49890 8006E490 24030010 */  addiu     $v1, $zero, 0x10
.L8006E494:
/* 49894 8006E494 00651006 */  srlv      $v0, $a1, $v1
/* 49898 8006E498 3C01800A */  lui       $at, %hi(D_8009A020)
/* 4989C 8006E49C 00220821 */  addu      $at, $at, $v0
/* 498A0 8006E4A0 9022A020 */  lbu       $v0, %lo(D_8009A020)($at)
/* 498A4 8006E4A4 00431021 */  addu      $v0, $v0, $v1
/* 498A8 8006E4A8 24030020 */  addiu     $v1, $zero, 0x20
/* 498AC 8006E4AC 00623023 */  subu      $a2, $v1, $v0
/* 498B0 8006E4B0 14C00004 */  bnez      $a2, .L8006E4C4
/* 498B4 8006E4B4 00662823 */   subu     $a1, $v1, $a2
/* 498B8 8006E4B8 00892023 */  subu      $a0, $a0, $t1
/* 498BC 8006E4BC 0801B96C */  j         .L8006E5B0
/* 498C0 8006E4C0 240A0001 */   addiu    $t2, $zero, 1
.L8006E4C4:
/* 498C4 8006E4C4 00C94804 */  sllv      $t1, $t1, $a2
/* 498C8 8006E4C8 00A43806 */  srlv      $a3, $a0, $a1
/* 498CC 8006E4CC 00C41804 */  sllv      $v1, $a0, $a2
/* 498D0 8006E4D0 00AB1006 */  srlv      $v0, $t3, $a1
/* 498D4 8006E4D4 00622025 */  or        $a0, $v1, $v0
/* 498D8 8006E4D8 00CB5804 */  sllv      $t3, $t3, $a2
/* 498DC 8006E4DC 00093402 */  srl       $a2, $t1, 0x10
/* 498E0 8006E4E0 14C00002 */  bnez      $a2, .L8006E4EC
/* 498E4 8006E4E4 00E6001B */   divu     $zero, $a3, $a2
/* 498E8 8006E4E8 0007000D */  break     7
.L8006E4EC:
/* 498EC 8006E4EC 00004012 */   mflo     $t0
/* 498F0 8006E4F0 00001810 */  mfhi      $v1
/* 498F4 8006E4F4 3125FFFF */  andi      $a1, $t1, 0xffff
/* 498F8 8006E4F8 00000000 */  nop
/* 498FC 8006E4FC 01050018 */  mult      $t0, $a1
/* 49900 8006E500 00041402 */  srl       $v0, $a0, 0x10
/* 49904 8006E504 00031C00 */  sll       $v1, $v1, 0x10
/* 49908 8006E508 00621825 */  or        $v1, $v1, $v0
/* 4990C 8006E50C 00003812 */  mflo      $a3
/* 49910 8006E510 0067102B */  sltu      $v0, $v1, $a3
/* 49914 8006E514 5040000B */  beql      $v0, $zero, .L8006E544
/* 49918 8006E518 00671823 */   subu     $v1, $v1, $a3
/* 4991C 8006E51C 00691821 */  addu      $v1, $v1, $t1
/* 49920 8006E520 0069102B */  sltu      $v0, $v1, $t1
/* 49924 8006E524 14400006 */  bnez      $v0, .L8006E540
/* 49928 8006E528 2508FFFF */   addiu    $t0, $t0, -1
/* 4992C 8006E52C 0067102B */  sltu      $v0, $v1, $a3
/* 49930 8006E530 50400004 */  beql      $v0, $zero, .L8006E544
/* 49934 8006E534 00671823 */   subu     $v1, $v1, $a3
/* 49938 8006E538 2508FFFF */  addiu     $t0, $t0, -1
/* 4993C 8006E53C 00691821 */  addu      $v1, $v1, $t1
.L8006E540:
/* 49940 8006E540 00671823 */  subu      $v1, $v1, $a3
.L8006E544:
/* 49944 8006E544 14C00002 */  bnez      $a2, .L8006E550
/* 49948 8006E548 0066001B */   divu     $zero, $v1, $a2
/* 4994C 8006E54C 0007000D */  break     7
.L8006E550:
/* 49950 8006E550 00003012 */   mflo     $a2
/* 49954 8006E554 00001810 */  mfhi      $v1
/* 49958 8006E558 00000000 */  nop
/* 4995C 8006E55C 00000000 */  nop
/* 49960 8006E560 00C50018 */  mult      $a2, $a1
/* 49964 8006E564 3082FFFF */  andi      $v0, $a0, 0xffff
/* 49968 8006E568 00031C00 */  sll       $v1, $v1, 0x10
/* 4996C 8006E56C 00621825 */  or        $v1, $v1, $v0
/* 49970 8006E570 00003812 */  mflo      $a3
/* 49974 8006E574 0067102B */  sltu      $v0, $v1, $a3
/* 49978 8006E578 1040000B */  beqz      $v0, .L8006E5A8
/* 4997C 8006E57C 00081400 */   sll      $v0, $t0, 0x10
/* 49980 8006E580 00691821 */  addu      $v1, $v1, $t1
/* 49984 8006E584 0069102B */  sltu      $v0, $v1, $t1
/* 49988 8006E588 14400006 */  bnez      $v0, .L8006E5A4
/* 4998C 8006E58C 24C6FFFF */   addiu    $a2, $a2, -1
/* 49990 8006E590 0067102B */  sltu      $v0, $v1, $a3
/* 49994 8006E594 10400004 */  beqz      $v0, .L8006E5A8
/* 49998 8006E598 00081400 */   sll      $v0, $t0, 0x10
/* 4999C 8006E59C 24C6FFFF */  addiu     $a2, $a2, -1
/* 499A0 8006E5A0 00691821 */  addu      $v1, $v1, $t1
.L8006E5A4:
/* 499A4 8006E5A4 00081400 */  sll       $v0, $t0, 0x10
.L8006E5A8:
/* 499A8 8006E5A8 00465025 */  or        $t2, $v0, $a2
/* 499AC 8006E5AC 00672023 */  subu      $a0, $v1, $a3
.L8006E5B0:
/* 499B0 8006E5B0 00093402 */  srl       $a2, $t1, 0x10
/* 499B4 8006E5B4 14C00002 */  bnez      $a2, .L8006E5C0
/* 499B8 8006E5B8 0086001B */   divu     $zero, $a0, $a2
/* 499BC 8006E5BC 0007000D */  break     7
.L8006E5C0:
/* 499C0 8006E5C0 00003812 */   mflo     $a3
/* 499C4 8006E5C4 00001810 */  mfhi      $v1
/* 499C8 8006E5C8 3128FFFF */  andi      $t0, $t1, 0xffff
/* 499CC 8006E5CC 00000000 */  nop
/* 499D0 8006E5D0 00E80018 */  mult      $a3, $t0
/* 499D4 8006E5D4 000B1402 */  srl       $v0, $t3, 0x10
/* 499D8 8006E5D8 00031C00 */  sll       $v1, $v1, 0x10
/* 499DC 8006E5DC 00621825 */  or        $v1, $v1, $v0
/* 499E0 8006E5E0 00002812 */  mflo      $a1
/* 499E4 8006E5E4 0065102B */  sltu      $v0, $v1, $a1
/* 499E8 8006E5E8 5040000B */  beql      $v0, $zero, .L8006E618
/* 499EC 8006E5EC 00651823 */   subu     $v1, $v1, $a1
/* 499F0 8006E5F0 00691821 */  addu      $v1, $v1, $t1
/* 499F4 8006E5F4 0069102B */  sltu      $v0, $v1, $t1
/* 499F8 8006E5F8 14400006 */  bnez      $v0, .L8006E614
/* 499FC 8006E5FC 24E7FFFF */   addiu    $a3, $a3, -1
/* 49A00 8006E600 0065102B */  sltu      $v0, $v1, $a1
/* 49A04 8006E604 50400004 */  beql      $v0, $zero, .L8006E618
/* 49A08 8006E608 00651823 */   subu     $v1, $v1, $a1
/* 49A0C 8006E60C 24E7FFFF */  addiu     $a3, $a3, -1
/* 49A10 8006E610 00691821 */  addu      $v1, $v1, $t1
.L8006E614:
/* 49A14 8006E614 00651823 */  subu      $v1, $v1, $a1
.L8006E618:
/* 49A18 8006E618 14C00002 */  bnez      $a2, .L8006E624
/* 49A1C 8006E61C 0066001B */   divu     $zero, $v1, $a2
/* 49A20 8006E620 0007000D */  break     7
.L8006E624:
/* 49A24 8006E624 00002012 */   mflo     $a0
/* 49A28 8006E628 00001810 */  mfhi      $v1
/* 49A2C 8006E62C 00000000 */  nop
/* 49A30 8006E630 00000000 */  nop
/* 49A34 8006E634 00880018 */  mult      $a0, $t0
/* 49A38 8006E638 3162FFFF */  andi      $v0, $t3, 0xffff
/* 49A3C 8006E63C 00031C00 */  sll       $v1, $v1, 0x10
/* 49A40 8006E640 00621825 */  or        $v1, $v1, $v0
/* 49A44 8006E644 00002812 */  mflo      $a1
/* 49A48 8006E648 0065102B */  sltu      $v0, $v1, $a1
/* 49A4C 8006E64C 10400007 */  beqz      $v0, .L8006E66C
/* 49A50 8006E650 00691821 */   addu     $v1, $v1, $t1
/* 49A54 8006E654 0069102B */  sltu      $v0, $v1, $t1
/* 49A58 8006E658 14400004 */  bnez      $v0, .L8006E66C
/* 49A5C 8006E65C 2484FFFF */   addiu    $a0, $a0, -1
/* 49A60 8006E660 0065102B */  sltu      $v0, $v1, $a1
/* 49A64 8006E664 54400001 */  bnel      $v0, $zero, .L8006E66C
/* 49A68 8006E668 2484FFFF */   addiu    $a0, $a0, -1
.L8006E66C:
/* 49A6C 8006E66C 00071400 */  sll       $v0, $a3, 0x10
/* 49A70 8006E670 0801BA0C */  j         .L8006E830
/* 49A74 8006E674 00443025 */   or       $a2, $v0, $a0
.L8006E678:
/* 49A78 8006E678 0088102B */  sltu      $v0, $a0, $t0
/* 49A7C 8006E67C 10400003 */  beqz      $v0, .L8006E68C
/* 49A80 8006E680 3402FFFF */   ori      $v0, $zero, 0xffff
/* 49A84 8006E684 0801BA0B */  j         .L8006E82C
/* 49A88 8006E688 0000302D */   daddu    $a2, $zero, $zero
.L8006E68C:
/* 49A8C 8006E68C 0048102B */  sltu      $v0, $v0, $t0
/* 49A90 8006E690 14400005 */  bnez      $v0, .L8006E6A8
/* 49A94 8006E694 0100282D */   daddu    $a1, $t0, $zero
/* 49A98 8006E698 2D020100 */  sltiu     $v0, $t0, 0x100
/* 49A9C 8006E69C 38420001 */  xori      $v0, $v0, 1
/* 49AA0 8006E6A0 0801B9B0 */  j         .L8006E6C0
/* 49AA4 8006E6A4 000218C0 */   sll      $v1, $v0, 3
.L8006E6A8:
/* 49AA8 8006E6A8 3C0200FF */  lui       $v0, 0xff
/* 49AAC 8006E6AC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49AB0 8006E6B0 0048102B */  sltu      $v0, $v0, $t0
/* 49AB4 8006E6B4 14400002 */  bnez      $v0, .L8006E6C0
/* 49AB8 8006E6B8 24030018 */   addiu    $v1, $zero, 0x18
/* 49ABC 8006E6BC 24030010 */  addiu     $v1, $zero, 0x10
.L8006E6C0:
/* 49AC0 8006E6C0 00651006 */  srlv      $v0, $a1, $v1
/* 49AC4 8006E6C4 3C01800A */  lui       $at, %hi(D_8009A020)
/* 49AC8 8006E6C8 00220821 */  addu      $at, $at, $v0
/* 49ACC 8006E6CC 9022A020 */  lbu       $v0, %lo(D_8009A020)($at)
/* 49AD0 8006E6D0 00431021 */  addu      $v0, $v0, $v1
/* 49AD4 8006E6D4 24030020 */  addiu     $v1, $zero, 0x20
/* 49AD8 8006E6D8 00623023 */  subu      $a2, $v1, $v0
/* 49ADC 8006E6DC 54C00009 */  bnel      $a2, $zero, .L8006E704
/* 49AE0 8006E6E0 00662823 */   subu     $a1, $v1, $a2
/* 49AE4 8006E6E4 0104102B */  sltu      $v0, $t0, $a0
/* 49AE8 8006E6E8 14400050 */  bnez      $v0, .L8006E82C
/* 49AEC 8006E6EC 24060001 */   addiu    $a2, $zero, 1
/* 49AF0 8006E6F0 0169102B */  sltu      $v0, $t3, $t1
/* 49AF4 8006E6F4 1440004D */  bnez      $v0, .L8006E82C
/* 49AF8 8006E6F8 0000302D */   daddu    $a2, $zero, $zero
/* 49AFC 8006E6FC 0801BA0B */  j         .L8006E82C
/* 49B00 8006E700 24060001 */   addiu    $a2, $zero, 1
.L8006E704:
/* 49B04 8006E704 00C81804 */  sllv      $v1, $t0, $a2
/* 49B08 8006E708 00A91006 */  srlv      $v0, $t1, $a1
/* 49B0C 8006E70C 00624025 */  or        $t0, $v1, $v0
/* 49B10 8006E710 00C94804 */  sllv      $t1, $t1, $a2
/* 49B14 8006E714 00A43806 */  srlv      $a3, $a0, $a1
/* 49B18 8006E718 00C41804 */  sllv      $v1, $a0, $a2
/* 49B1C 8006E71C 00AB1006 */  srlv      $v0, $t3, $a1
/* 49B20 8006E720 00622025 */  or        $a0, $v1, $v0
/* 49B24 8006E724 00CB5804 */  sllv      $t3, $t3, $a2
/* 49B28 8006E728 00083402 */  srl       $a2, $t0, 0x10
/* 49B2C 8006E72C 14C00002 */  bnez      $a2, .L8006E738
/* 49B30 8006E730 00E6001B */   divu     $zero, $a3, $a2
/* 49B34 8006E734 0007000D */  break     7
.L8006E738:
/* 49B38 8006E738 00005012 */   mflo     $t2
/* 49B3C 8006E73C 00001810 */  mfhi      $v1
/* 49B40 8006E740 3105FFFF */  andi      $a1, $t0, 0xffff
/* 49B44 8006E744 00000000 */  nop
/* 49B48 8006E748 01450018 */  mult      $t2, $a1
/* 49B4C 8006E74C 00041402 */  srl       $v0, $a0, 0x10
/* 49B50 8006E750 00031C00 */  sll       $v1, $v1, 0x10
/* 49B54 8006E754 00621825 */  or        $v1, $v1, $v0
/* 49B58 8006E758 00003812 */  mflo      $a3
/* 49B5C 8006E75C 0067102B */  sltu      $v0, $v1, $a3
/* 49B60 8006E760 5040000B */  beql      $v0, $zero, .L8006E790
/* 49B64 8006E764 00671823 */   subu     $v1, $v1, $a3
/* 49B68 8006E768 00681821 */  addu      $v1, $v1, $t0
/* 49B6C 8006E76C 0068102B */  sltu      $v0, $v1, $t0
/* 49B70 8006E770 14400006 */  bnez      $v0, .L8006E78C
/* 49B74 8006E774 254AFFFF */   addiu    $t2, $t2, -1
/* 49B78 8006E778 0067102B */  sltu      $v0, $v1, $a3
/* 49B7C 8006E77C 50400004 */  beql      $v0, $zero, .L8006E790
/* 49B80 8006E780 00671823 */   subu     $v1, $v1, $a3
/* 49B84 8006E784 254AFFFF */  addiu     $t2, $t2, -1
/* 49B88 8006E788 00681821 */  addu      $v1, $v1, $t0
.L8006E78C:
/* 49B8C 8006E78C 00671823 */  subu      $v1, $v1, $a3
.L8006E790:
/* 49B90 8006E790 14C00002 */  bnez      $a2, .L8006E79C
/* 49B94 8006E794 0066001B */   divu     $zero, $v1, $a2
/* 49B98 8006E798 0007000D */  break     7
.L8006E79C:
/* 49B9C 8006E79C 00003012 */   mflo     $a2
/* 49BA0 8006E7A0 00001810 */  mfhi      $v1
/* 49BA4 8006E7A4 00000000 */  nop
/* 49BA8 8006E7A8 00000000 */  nop
/* 49BAC 8006E7AC 00C50018 */  mult      $a2, $a1
/* 49BB0 8006E7B0 3082FFFF */  andi      $v0, $a0, 0xffff
/* 49BB4 8006E7B4 00031C00 */  sll       $v1, $v1, 0x10
/* 49BB8 8006E7B8 00621825 */  or        $v1, $v1, $v0
/* 49BBC 8006E7BC 00003812 */  mflo      $a3
/* 49BC0 8006E7C0 0067102B */  sltu      $v0, $v1, $a3
/* 49BC4 8006E7C4 1040000B */  beqz      $v0, .L8006E7F4
/* 49BC8 8006E7C8 000A1400 */   sll      $v0, $t2, 0x10
/* 49BCC 8006E7CC 00681821 */  addu      $v1, $v1, $t0
/* 49BD0 8006E7D0 0068102B */  sltu      $v0, $v1, $t0
/* 49BD4 8006E7D4 14400006 */  bnez      $v0, .L8006E7F0
/* 49BD8 8006E7D8 24C6FFFF */   addiu    $a2, $a2, -1
/* 49BDC 8006E7DC 0067102B */  sltu      $v0, $v1, $a3
/* 49BE0 8006E7E0 10400004 */  beqz      $v0, .L8006E7F4
/* 49BE4 8006E7E4 000A1400 */   sll      $v0, $t2, 0x10
/* 49BE8 8006E7E8 24C6FFFF */  addiu     $a2, $a2, -1
/* 49BEC 8006E7EC 00681821 */  addu      $v1, $v1, $t0
.L8006E7F0:
/* 49BF0 8006E7F0 000A1400 */  sll       $v0, $t2, 0x10
.L8006E7F4:
/* 49BF4 8006E7F4 00463025 */  or        $a2, $v0, $a2
/* 49BF8 8006E7F8 00672023 */  subu      $a0, $v1, $a3
/* 49BFC 8006E7FC 00C90019 */  multu     $a2, $t1
/* 49C00 8006E800 00001810 */  mfhi      $v1
/* 49C04 8006E804 0083102B */  sltu      $v0, $a0, $v1
/* 49C08 8006E808 00004012 */  mflo      $t0
/* 49C0C 8006E80C 54400007 */  bnel      $v0, $zero, .L8006E82C
/* 49C10 8006E810 24C6FFFF */   addiu    $a2, $a2, -1
/* 49C14 8006E814 14640006 */  bne       $v1, $a0, .L8006E830
/* 49C18 8006E818 0000502D */   daddu    $t2, $zero, $zero
/* 49C1C 8006E81C 0168102B */  sltu      $v0, $t3, $t0
/* 49C20 8006E820 10400004 */  beqz      $v0, .L8006E834
/* 49C24 8006E824 00C0682D */   daddu    $t5, $a2, $zero
/* 49C28 8006E828 24C6FFFF */  addiu     $a2, $a2, -1
.L8006E82C:
/* 49C2C 8006E82C 0000502D */  daddu     $t2, $zero, $zero
.L8006E830:
/* 49C30 8006E830 00C0682D */  daddu     $t5, $a2, $zero
.L8006E834:
/* 49C34 8006E834 0140602D */  daddu     $t4, $t2, $zero
/* 49C38 8006E838 0180102D */  daddu     $v0, $t4, $zero
/* 49C3C 8006E83C 03E00008 */  jr        $ra
/* 49C40 8006E840 01A0182D */   daddu    $v1, $t5, $zero
/* 49C44 8006E844 00000000 */  nop
/* 49C48 8006E848 00000000 */  nop
/* 49C4C 8006E84C 00000000 */  nop
