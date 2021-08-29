.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240384_946254
/* 946254 80240384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 946258 80240388 AFBF0010 */  sw        $ra, 0x10($sp)
/* 94625C 8024038C 10A00003 */  beqz      $a1, .L8024039C
/* 946260 80240390 8C86000C */   lw       $a2, 0xc($a0)
/* 946264 80240394 3C018024 */  lui       $at, %hi(D_80240E00_946CD0)
/* 946268 80240398 AC200E00 */  sw        $zero, %lo(D_80240E00_946CD0)($at)
.L8024039C:
/* 94626C 8024039C 3C038024 */  lui       $v1, %hi(D_80240E00_946CD0)
/* 946270 802403A0 24630E00 */  addiu     $v1, $v1, %lo(D_80240E00_946CD0)
/* 946274 802403A4 8C620000 */  lw        $v0, ($v1)
/* 946278 802403A8 54400003 */  bnel      $v0, $zero, .L802403B8
/* 94627C 802403AC AC600000 */   sw       $zero, ($v1)
/* 946280 802403B0 080900F3 */  j         .L802403CC
/* 946284 802403B4 0000102D */   daddu    $v0, $zero, $zero
.L802403B8:
/* 946288 802403B8 8CC50000 */  lw        $a1, ($a2)
/* 94628C 802403BC 3C068024 */  lui       $a2, %hi(D_80240E04_946CD4)
/* 946290 802403C0 0C0B2026 */  jal       evt_set_variable
/* 946294 802403C4 8CC60E04 */   lw       $a2, %lo(D_80240E04_946CD4)($a2)
/* 946298 802403C8 24020002 */  addiu     $v0, $zero, 2
.L802403CC:
/* 94629C 802403CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9462A0 802403D0 03E00008 */  jr        $ra
/* 9462A4 802403D4 27BD0018 */   addiu    $sp, $sp, 0x18
