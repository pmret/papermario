.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FF0_D7FD50
/* D7FD50 80240FF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7FD54 80240FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* D7FD58 80240FF8 0080802D */  daddu     $s0, $a0, $zero
/* D7FD5C 80240FFC AFBF0014 */  sw        $ra, 0x14($sp)
/* D7FD60 80241000 8E02000C */  lw        $v0, 0xc($s0)
/* D7FD64 80241004 0C0B1EAF */  jal       evt_get_variable
/* D7FD68 80241008 8C450000 */   lw       $a1, ($v0)
/* D7FD6C 8024100C 0040302D */  daddu     $a2, $v0, $zero
/* D7FD70 80241010 3C058016 */  lui       $a1, %hi(gCollisionStatus)
/* D7FD74 80241014 84A5A550 */  lh        $a1, %lo(gCollisionStatus)($a1)
/* D7FD78 80241018 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* D7FD7C 8024101C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* D7FD80 80241020 10A60004 */  beq       $a1, $a2, .L80241034
/* D7FD84 80241024 24020014 */   addiu    $v0, $zero, 0x14
/* D7FD88 80241028 808300B4 */  lb        $v1, 0xb4($a0)
/* D7FD8C 8024102C 10620006 */  beq       $v1, $v0, .L80241048
/* D7FD90 80241030 00000000 */   nop
.L80241034:
/* D7FD94 80241034 8C820014 */  lw        $v0, 0x14($a0)
/* D7FD98 80241038 3C03FFFF */  lui       $v1, 0xffff
/* D7FD9C 8024103C 00431024 */  and       $v0, $v0, $v1
/* D7FDA0 80241040 10400005 */  beqz      $v0, .L80241058
/* D7FDA4 80241044 00000000 */   nop
.L80241048:
/* D7FDA8 80241048 0C039769 */  jal       set_action_state
/* D7FDAC 8024104C 0000202D */   daddu    $a0, $zero, $zero
/* D7FDB0 80241050 08090426 */  j         .L80241098
/* D7FDB4 80241054 AE000084 */   sw       $zero, 0x84($s0)
.L80241058:
/* D7FDB8 80241058 54A6000F */  bnel      $a1, $a2, .L80241098
/* D7FDBC 8024105C AE000084 */   sw       $zero, 0x84($s0)
/* D7FDC0 80241060 808300B4 */  lb        $v1, 0xb4($a0)
/* D7FDC4 80241064 24020014 */  addiu     $v0, $zero, 0x14
/* D7FDC8 80241068 10620005 */  beq       $v1, $v0, .L80241080
/* D7FDCC 8024106C 24020001 */   addiu    $v0, $zero, 1
/* D7FDD0 80241070 10620003 */  beq       $v1, $v0, .L80241080
/* D7FDD4 80241074 24020002 */   addiu    $v0, $zero, 2
/* D7FDD8 80241078 54620008 */  bnel      $v1, $v0, .L8024109C
/* D7FDDC 8024107C AE000084 */   sw       $zero, 0x84($s0)
.L80241080:
/* D7FDE0 80241080 8C820004 */  lw        $v0, 4($a0)
/* D7FDE4 80241084 30420001 */  andi      $v0, $v0, 1
/* D7FDE8 80241088 54400003 */  bnel      $v0, $zero, .L80241098
/* D7FDEC 8024108C AE000084 */   sw       $zero, 0x84($s0)
/* D7FDF0 80241090 24020001 */  addiu     $v0, $zero, 1
/* D7FDF4 80241094 AE020084 */  sw        $v0, 0x84($s0)
.L80241098:
/* D7FDF8 80241098 24020002 */  addiu     $v0, $zero, 2
.L8024109C:
/* D7FDFC 8024109C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7FE00 802410A0 8FB00010 */  lw        $s0, 0x10($sp)
/* D7FE04 802410A4 03E00008 */  jr        $ra
/* D7FE08 802410A8 27BD0018 */   addiu    $sp, $sp, 0x18
/* D7FE0C 802410AC 00000000 */  nop
