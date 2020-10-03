.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F4FC4
/* 8E474 800F4FC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8E478 800F4FC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8E47C 800F4FCC 3C108011 */  lui       $s0, 0x8011
/* 8E480 800F4FD0 2610D69C */  addiu     $s0, $s0, -0x2964
/* 8E484 800F4FD4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8E488 800F4FD8 AE040000 */  sw        $a0, ($s0)
/* 8E48C 800F4FDC A480032C */  sh        $zero, 0x32c($a0)
/* 8E490 800F4FE0 AC80031C */  sw        $zero, 0x31c($a0)
/* 8E494 800F4FE4 0C03A635 */  jal       func_800E98D4
/* 8E498 800F4FE8 AC800320 */   sw       $zero, 0x320($a0)
/* 8E49C 800F4FEC 3C048011 */  lui       $a0, 0x8011
/* 8E4A0 800F4FF0 2484D699 */  addiu     $a0, $a0, -0x2967
/* 8E4A4 800F4FF4 3C018011 */  lui       $at, 0x8011
/* 8E4A8 800F4FF8 A022D69A */  sb        $v0, -0x2966($at)
/* 8E4AC 800F4FFC A0800000 */  sb        $zero, ($a0)
/* 8E4B0 800F5000 8E100000 */  lw        $s0, ($s0)
/* 8E4B4 800F5004 3C068011 */  lui       $a2, 0x8011
/* 8E4B8 800F5008 24C6D698 */  addiu     $a2, $a2, -0x2968
/* 8E4BC 800F500C 8E030318 */  lw        $v1, 0x318($s0)
/* 8E4C0 800F5010 24050001 */  addiu     $a1, $zero, 1
/* 8E4C4 800F5014 28620064 */  slti      $v0, $v1, 0x64
/* 8E4C8 800F5018 1440000C */  bnez      $v0, .L800F504C
/* 8E4CC 800F501C A0C50000 */   sb       $a1, ($a2)
/* 8E4D0 800F5020 2462FF9C */  addiu     $v0, $v1, -0x64
/* 8E4D4 800F5024 AE020318 */  sw        $v0, 0x318($s0)
/* 8E4D8 800F5028 0040182D */  daddu     $v1, $v0, $zero
/* 8E4DC 800F502C 28620064 */  slti      $v0, $v1, 0x64
/* 8E4E0 800F5030 14400005 */  bnez      $v0, .L800F5048
/* 8E4E4 800F5034 A0850000 */   sb       $a1, ($a0)
/* 8E4E8 800F5038 2462FF9C */  addiu     $v0, $v1, -0x64
/* 8E4EC 800F503C AE020318 */  sw        $v0, 0x318($s0)
/* 8E4F0 800F5040 24020002 */  addiu     $v0, $zero, 2
/* 8E4F4 800F5044 A0820000 */  sb        $v0, ($a0)
.L800F5048:
/* 8E4F8 800F5048 A0C00000 */  sb        $zero, ($a2)
.L800F504C:
/* 8E4FC 800F504C 3C058011 */  lui       $a1, 0x8011
/* 8E500 800F5050 8CA5D69C */  lw        $a1, -0x2964($a1)
/* 8E504 800F5054 24020001 */  addiu     $v0, $zero, 1
/* 8E508 800F5058 3C018011 */  lui       $at, 0x8011
/* 8E50C 800F505C A022D68E */  sb        $v0, -0x2972($at)
/* 8E510 800F5060 24020006 */  addiu     $v0, $zero, 6
/* 8E514 800F5064 3C018011 */  lui       $at, 0x8011
/* 8E518 800F5068 A022D68F */  sb        $v0, -0x2971($at)
/* 8E51C 800F506C 8CA20328 */  lw        $v0, 0x328($a1)
/* 8E520 800F5070 8CA40324 */  lw        $a0, 0x324($a1)
/* 8E524 800F5074 3C038011 */  lui       $v1, 0x8011
/* 8E528 800F5078 2463D648 */  addiu     $v1, $v1, -0x29b8
/* 8E52C 800F507C 3C018011 */  lui       $at, 0x8011
/* 8E530 800F5080 AC20D640 */  sw        $zero, -0x29c0($at)
/* 8E534 800F5084 AC620000 */  sw        $v0, ($v1)
/* 8E538 800F5088 0044102A */  slt       $v0, $v0, $a0
/* 8E53C 800F508C 14400002 */  bnez      $v0, .L800F5098
/* 8E540 800F5090 2482FFFF */   addiu    $v0, $a0, -1
/* 8E544 800F5094 AC620000 */  sw        $v0, ($v1)
.L800F5098:
/* 8E548 800F5098 8C620000 */  lw        $v0, ($v1)
/* 8E54C 800F509C 3C048011 */  lui       $a0, 0x8011
/* 8E550 800F50A0 2484D656 */  addiu     $a0, $a0, -0x29aa
/* 8E554 800F50A4 3C018011 */  lui       $at, 0x8011
/* 8E558 800F50A8 A020D654 */  sb        $zero, -0x29ac($at)
/* 8E55C 800F50AC 3C018011 */  lui       $at, 0x8011
/* 8E560 800F50B0 AC22D64C */  sw        $v0, -0x29b4($at)
/* 8E564 800F50B4 90A20327 */  lbu       $v0, 0x327($a1)
/* 8E568 800F50B8 24030006 */  addiu     $v1, $zero, 6
/* 8E56C 800F50BC A0820000 */  sb        $v0, ($a0)
/* 8E570 800F50C0 00021600 */  sll       $v0, $v0, 0x18
/* 8E574 800F50C4 00021603 */  sra       $v0, $v0, 0x18
/* 8E578 800F50C8 0062102A */  slt       $v0, $v1, $v0
/* 8E57C 800F50CC 54400001 */  bnel      $v0, $zero, .L800F50D4
/* 8E580 800F50D0 A0830000 */   sb       $v1, ($a0)
.L800F50D4:
/* 8E584 800F50D4 8CA20324 */  lw        $v0, 0x324($a1)
/* 8E588 800F50D8 3C048011 */  lui       $a0, 0x8011
/* 8E58C 800F50DC 2484D655 */  addiu     $a0, $a0, -0x29ab
/* 8E590 800F50E0 28420006 */  slti      $v0, $v0, 6
/* 8E594 800F50E4 10400003 */  beqz      $v0, .L800F50F4
/* 8E598 800F50E8 A0830000 */   sb       $v1, ($a0)
/* 8E59C 800F50EC 90A20327 */  lbu       $v0, 0x327($a1)
/* 8E5A0 800F50F0 A0820000 */  sb        $v0, ($a0)
.L800F50F4:
/* 8E5A4 800F50F4 240200FF */  addiu     $v0, $zero, 0xff
/* 8E5A8 800F50F8 3C018011 */  lui       $at, 0x8011
/* 8E5AC 800F50FC AC22D650 */  sw        $v0, -0x29b0($at)
/* 8E5B0 800F5100 24020004 */  addiu     $v0, $zero, 4
/* 8E5B4 800F5104 3C04800F */  lui       $a0, 0x800f
/* 8E5B8 800F5108 24841A10 */  addiu     $a0, $a0, 0x1a10
/* 8E5BC 800F510C 3C018011 */  lui       $at, 0x8011
/* 8E5C0 800F5110 A022D691 */  sb        $v0, -0x296f($at)
/* 8E5C4 800F5114 3C018011 */  lui       $at, 0x8011
/* 8E5C8 800F5118 A023D692 */  sb        $v1, -0x296e($at)
/* 8E5CC 800F511C 0C048C8F */  jal       bind_dynamic_entity_7
/* 8E5D0 800F5120 0000282D */   daddu    $a1, $zero, $zero
/* 8E5D4 800F5124 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8E5D8 800F5128 8FB00010 */  lw        $s0, 0x10($sp)
/* 8E5DC 800F512C 3C018011 */  lui       $at, 0x8011
/* 8E5E0 800F5130 AC22D694 */  sw        $v0, -0x296c($at)
/* 8E5E4 800F5134 03E00008 */  jr        $ra
/* 8E5E8 800F5138 27BD0018 */   addiu    $sp, $sp, 0x18
