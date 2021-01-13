.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80132D94
/* C9494 80132D94 3C02800A */  lui       $v0, %hi(D_8009A650)
/* C9498 80132D98 8C42A650 */  lw        $v0, %lo(D_8009A650)($v0)
/* C949C 80132D9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C94A0 80132DA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C94A4 80132DA4 AFB10014 */  sw        $s1, 0x14($sp)
/* C94A8 80132DA8 3042C000 */  andi      $v0, $v0, 0xc000
/* C94AC 80132DAC 14400024 */  bnez      $v0, .L80132E40
/* C94B0 80132DB0 AFB00010 */   sw       $s0, 0x10($sp)
/* C94B4 80132DB4 0000802D */  daddu     $s0, $zero, $zero
/* C94B8 80132DB8 3C118015 */  lui       $s1, %hi(D_80150CC8)
/* C94BC 80132DBC 26310CC8 */  addiu     $s1, $s1, %lo(D_80150CC8)
.L80132DC0:
/* C94C0 80132DC0 3C038015 */  lui       $v1, %hi(D_801565A0)
/* C94C4 80132DC4 8C6365A0 */  lw        $v1, %lo(D_801565A0)($v1)
/* C94C8 80132DC8 00101080 */  sll       $v0, $s0, 2
/* C94CC 80132DCC 00431021 */  addu      $v0, $v0, $v1
/* C94D0 80132DD0 8C440000 */  lw        $a0, ($v0)
/* C94D4 80132DD4 50800017 */  beql      $a0, $zero, .L80132E34
/* C94D8 80132DD8 26100001 */   addiu    $s0, $s0, 1
/* C94DC 80132DDC 8C820000 */  lw        $v0, ($a0)
/* C94E0 80132DE0 50400014 */  beql      $v0, $zero, .L80132E34
/* C94E4 80132DE4 26100001 */   addiu    $s0, $s0, 1
/* C94E8 80132DE8 8083001B */  lb        $v1, 0x1b($a0)
/* C94EC 80132DEC 2C620018 */  sltiu     $v0, $v1, 0x18
/* C94F0 80132DF0 1040000F */  beqz      $v0, .L80132E30
/* C94F4 80132DF4 00031080 */   sll      $v0, $v1, 2
/* C94F8 80132DF8 00511021 */  addu      $v0, $v0, $s1
/* C94FC 80132DFC 8C420000 */  lw        $v0, ($v0)
/* C9500 80132E00 00400008 */  jr        $v0
/* C9504 80132E04 00000000 */   nop
/* C9508 80132E08 0C04D5B1 */  jal       func_801356C4
/* C950C 80132E0C 26100001 */   addiu    $s0, $s0, 1
/* C9510 80132E10 0804CB8E */  j         .L80132E38
/* C9514 80132E14 2A020100 */   slti     $v0, $s0, 0x100
/* C9518 80132E18 0C04D5B5 */  jal       func_801356D4
/* C951C 80132E1C 26100001 */   addiu    $s0, $s0, 1
/* C9520 80132E20 0804CB8E */  j         .L80132E38
/* C9524 80132E24 2A020100 */   slti     $v0, $s0, 0x100
/* C9528 80132E28 0C04D567 */  jal       func_8013559C
/* C952C 80132E2C 00000000 */   nop
.L80132E30:
/* C9530 80132E30 26100001 */  addiu     $s0, $s0, 1
.L80132E34:
/* C9534 80132E34 2A020100 */  slti      $v0, $s0, 0x100
.L80132E38:
/* C9538 80132E38 1440FFE1 */  bnez      $v0, .L80132DC0
/* C953C 80132E3C 00000000 */   nop
.L80132E40:
/* C9540 80132E40 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9544 80132E44 8FB10014 */  lw        $s1, 0x14($sp)
/* C9548 80132E48 8FB00010 */  lw        $s0, 0x10($sp)
/* C954C 80132E4C 03E00008 */  jr        $ra
/* C9550 80132E50 27BD0020 */   addiu    $sp, $sp, 0x20
