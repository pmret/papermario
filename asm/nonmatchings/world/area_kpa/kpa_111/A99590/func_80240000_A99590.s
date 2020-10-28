.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A99590
/* A99590 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A99594 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* A99598 80240008 0080802D */  daddu     $s0, $a0, $zero
/* A9959C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* A995A0 80240010 8E02000C */  lw        $v0, 0xc($s0)
/* A995A4 80240014 0C0B1EAF */  jal       get_variable
/* A995A8 80240018 8C450000 */   lw       $a1, ($v0)
/* A995AC 8024001C 0040302D */  daddu     $a2, $v0, $zero
/* A995B0 80240020 3C058016 */  lui       $a1, %hi(gCollisionStatus)
/* A995B4 80240024 84A5A550 */  lh        $a1, %lo(gCollisionStatus)($a1)
/* A995B8 80240028 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* A995BC 8024002C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* A995C0 80240030 10A60004 */  beq       $a1, $a2, .L80240044
/* A995C4 80240034 24020014 */   addiu    $v0, $zero, 0x14
/* A995C8 80240038 808300B4 */  lb        $v1, 0xb4($a0)
/* A995CC 8024003C 10620006 */  beq       $v1, $v0, .L80240058
/* A995D0 80240040 00000000 */   nop      
.L80240044:
/* A995D4 80240044 8C820014 */  lw        $v0, 0x14($a0)
/* A995D8 80240048 3C03FFFF */  lui       $v1, 0xffff
/* A995DC 8024004C 00431024 */  and       $v0, $v0, $v1
/* A995E0 80240050 10400005 */  beqz      $v0, .L80240068
/* A995E4 80240054 00000000 */   nop      
.L80240058:
/* A995E8 80240058 0C039769 */  jal       set_action_state
/* A995EC 8024005C 0000202D */   daddu    $a0, $zero, $zero
/* A995F0 80240060 0809002A */  j         .L802400A8
/* A995F4 80240064 AE000084 */   sw       $zero, 0x84($s0)
.L80240068:
/* A995F8 80240068 54A6000F */  bnel      $a1, $a2, .L802400A8
/* A995FC 8024006C AE000084 */   sw       $zero, 0x84($s0)
/* A99600 80240070 808300B4 */  lb        $v1, 0xb4($a0)
/* A99604 80240074 24020014 */  addiu     $v0, $zero, 0x14
/* A99608 80240078 10620005 */  beq       $v1, $v0, .L80240090
/* A9960C 8024007C 24020001 */   addiu    $v0, $zero, 1
/* A99610 80240080 10620003 */  beq       $v1, $v0, .L80240090
/* A99614 80240084 24020002 */   addiu    $v0, $zero, 2
/* A99618 80240088 54620008 */  bnel      $v1, $v0, .L802400AC
/* A9961C 8024008C AE000084 */   sw       $zero, 0x84($s0)
.L80240090:
/* A99620 80240090 8C820004 */  lw        $v0, 4($a0)
/* A99624 80240094 30420001 */  andi      $v0, $v0, 1
/* A99628 80240098 54400003 */  bnel      $v0, $zero, .L802400A8
/* A9962C 8024009C AE000084 */   sw       $zero, 0x84($s0)
/* A99630 802400A0 24020001 */  addiu     $v0, $zero, 1
/* A99634 802400A4 AE020084 */  sw        $v0, 0x84($s0)
.L802400A8:
/* A99638 802400A8 24020002 */  addiu     $v0, $zero, 2
.L802400AC:
/* A9963C 802400AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A99640 802400B0 8FB00010 */  lw        $s0, 0x10($sp)
/* A99644 802400B4 03E00008 */  jr        $ra
/* A99648 802400B8 27BD0018 */   addiu    $sp, $sp, 0x18
