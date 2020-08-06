.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80027600
/* 002A00 80027600 27BDFF98 */  addiu $sp, $sp, -0x68
/* 002A04 80027604 0080502D */  daddu $t2, $a0, $zero
/* 002A08 80027608 0000302D */  daddu $a2, $zero, $zero
/* 002A0C 8002760C 27A90008 */  addiu $t1, $sp, 8
/* 002A10 80027610 27A80028 */  addiu $t0, $sp, 0x28
/* 002A14 80027614 27A70048 */  addiu $a3, $sp, 0x48
.L80027618:
/* 002A18 80027618 01261021 */  addu  $v0, $t1, $a2
/* 002A1C 8002761C 01061821 */  addu  $v1, $t0, $a2
/* 002A20 80027620 00E62021 */  addu  $a0, $a3, $a2
/* 002A24 80027624 24C60001 */  addiu $a2, $a2, 1
/* 002A28 80027628 A0400000 */  sb    $zero, ($v0)
/* 002A2C 8002762C 28C20020 */  slti  $v0, $a2, 0x20
/* 002A30 80027630 A0600000 */  sb    $zero, ($v1)
/* 002A34 80027634 1440FFF8 */  bnez  $v0, .L80027618
/* 002A38 80027638 A0800000 */   sb    $zero, ($a0)
/* 002A3C 8002763C 0000302D */  daddu $a2, $zero, $zero
/* 002A40 80027640 27A90008 */  addiu $t1, $sp, 8
/* 002A44 80027644 27A80028 */  addiu $t0, $sp, 0x28
/* 002A48 80027648 27A70048 */  addiu $a3, $sp, 0x48
/* 002A4C 8002764C 0140202D */  daddu $a0, $t2, $zero
.L80027650:
/* 002A50 80027650 90830000 */  lbu   $v1, ($a0)
/* 002A54 80027654 01231821 */  addu  $v1, $t1, $v1
/* 002A58 80027658 90620000 */  lbu   $v0, ($v1)
/* 002A5C 8002765C 24420001 */  addiu $v0, $v0, 1
/* 002A60 80027660 A0620000 */  sb    $v0, ($v1)
/* 002A64 80027664 90830001 */  lbu   $v1, 1($a0)
/* 002A68 80027668 01031821 */  addu  $v1, $t0, $v1
/* 002A6C 8002766C 90620000 */  lbu   $v0, ($v1)
/* 002A70 80027670 24420001 */  addiu $v0, $v0, 1
/* 002A74 80027674 A0620000 */  sb    $v0, ($v1)
/* 002A78 80027678 90830002 */  lbu   $v1, 2($a0)
/* 002A7C 8002767C 24C60001 */  addiu $a2, $a2, 1
/* 002A80 80027680 00E31821 */  addu  $v1, $a3, $v1
/* 002A84 80027684 90620000 */  lbu   $v0, ($v1)
/* 002A88 80027688 24420001 */  addiu $v0, $v0, 1
/* 002A8C 8002768C A0620000 */  sb    $v0, ($v1)
/* 002A90 80027690 28C20009 */  slti  $v0, $a2, 9
/* 002A94 80027694 1440FFEE */  bnez  $v0, .L80027650
/* 002A98 80027698 24840004 */   addiu $a0, $a0, 4
/* 002A9C 8002769C 0000182D */  daddu $v1, $zero, $zero
/* 002AA0 800276A0 0060302D */  daddu $a2, $v1, $zero
/* 002AA4 800276A4 27A40008 */  addiu $a0, $sp, 8
/* 002AA8 800276A8 00861021 */  addu  $v0, $a0, $a2
.L800276AC:
/* 002AAC 800276AC 90420000 */  lbu   $v0, ($v0)
/* 002AB0 800276B0 00621821 */  addu  $v1, $v1, $v0
/* 002AB4 800276B4 28620005 */  slti  $v0, $v1, 5
/* 002AB8 800276B8 50400006 */  beql  $v0, $zero, .L800276D4
/* 002ABC 800276BC A3A60000 */   sb    $a2, ($sp)
/* 002AC0 800276C0 24C60001 */  addiu $a2, $a2, 1
/* 002AC4 800276C4 28C20020 */  slti  $v0, $a2, 0x20
/* 002AC8 800276C8 1440FFF8 */  bnez  $v0, .L800276AC
/* 002ACC 800276CC 00861021 */   addu  $v0, $a0, $a2
/* 002AD0 800276D0 A3A60000 */  sb    $a2, ($sp)
.L800276D4:
/* 002AD4 800276D4 0000182D */  daddu $v1, $zero, $zero
/* 002AD8 800276D8 0060302D */  daddu $a2, $v1, $zero
/* 002ADC 800276DC 27A40028 */  addiu $a0, $sp, 0x28
/* 002AE0 800276E0 00861021 */  addu  $v0, $a0, $a2
.L800276E4:
/* 002AE4 800276E4 90420000 */  lbu   $v0, ($v0)
/* 002AE8 800276E8 00621821 */  addu  $v1, $v1, $v0
/* 002AEC 800276EC 28620005 */  slti  $v0, $v1, 5
/* 002AF0 800276F0 50400006 */  beql  $v0, $zero, .L8002770C
/* 002AF4 800276F4 A3A60001 */   sb    $a2, 1($sp)
/* 002AF8 800276F8 24C60001 */  addiu $a2, $a2, 1
/* 002AFC 800276FC 28C20020 */  slti  $v0, $a2, 0x20
/* 002B00 80027700 1440FFF8 */  bnez  $v0, .L800276E4
/* 002B04 80027704 00861021 */   addu  $v0, $a0, $a2
/* 002B08 80027708 A3A60001 */  sb    $a2, 1($sp)
.L8002770C:
/* 002B0C 8002770C 0000182D */  daddu $v1, $zero, $zero
/* 002B10 80027710 0060302D */  daddu $a2, $v1, $zero
/* 002B14 80027714 27A40048 */  addiu $a0, $sp, 0x48
/* 002B18 80027718 00861021 */  addu  $v0, $a0, $a2
.L8002771C:
/* 002B1C 8002771C 90420000 */  lbu   $v0, ($v0)
/* 002B20 80027720 00621821 */  addu  $v1, $v1, $v0
/* 002B24 80027724 28620005 */  slti  $v0, $v1, 5
/* 002B28 80027728 50400006 */  beql  $v0, $zero, .L80027744
/* 002B2C 8002772C A3A60002 */   sb    $a2, 2($sp)
/* 002B30 80027730 24C60001 */  addiu $a2, $a2, 1
/* 002B34 80027734 28C20020 */  slti  $v0, $a2, 0x20
/* 002B38 80027738 1440FFF8 */  bnez  $v0, .L8002771C
/* 002B3C 8002773C 00861021 */   addu  $v0, $a0, $a2
/* 002B40 80027740 A3A60002 */  sb    $a2, 2($sp)
.L80027744:
/* 002B44 80027744 30C300FF */  andi  $v1, $a2, 0xff
/* 002B48 80027748 00031840 */  sll   $v1, $v1, 1
/* 002B4C 8002774C 93A20000 */  lbu   $v0, ($sp)
/* 002B50 80027750 93A40001 */  lbu   $a0, 1($sp)
/* 002B54 80027754 000212C0 */  sll   $v0, $v0, 0xb
/* 002B58 80027758 00042180 */  sll   $a0, $a0, 6
/* 002B5C 8002775C 00441021 */  addu  $v0, $v0, $a0
/* 002B60 80027760 00431021 */  addu  $v0, $v0, $v1
/* 002B64 80027764 24420001 */  addiu $v0, $v0, 1
/* 002B68 80027768 A4A20000 */  sh    $v0, ($a1)
/* 002B6C 8002776C 03E00008 */  jr    $ra
/* 002B70 80027770 27BD0068 */   addiu $sp, $sp, 0x68


