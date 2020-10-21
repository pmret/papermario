.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024226C_8B22DC
/* 8B22DC 8024226C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B22E0 80242270 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B22E4 80242274 10A00003 */  beqz      $a1, .L80242284
/* 8B22E8 80242278 8C86000C */   lw       $a2, 0xc($a0)
/* 8B22EC 8024227C 3C018024 */  lui       $at, 0x8024
/* 8B22F0 80242280 AC207E30 */  sw        $zero, 0x7e30($at)
.L80242284:
/* 8B22F4 80242284 3C038024 */  lui       $v1, 0x8024
/* 8B22F8 80242288 24637E30 */  addiu     $v1, $v1, 0x7e30
/* 8B22FC 8024228C 8C620000 */  lw        $v0, ($v1)
/* 8B2300 80242290 54400003 */  bnel      $v0, $zero, .L802422A0
/* 8B2304 80242294 AC600000 */   sw       $zero, ($v1)
/* 8B2308 80242298 080908AD */  j         .L802422B4
/* 8B230C 8024229C 0000102D */   daddu    $v0, $zero, $zero
.L802422A0:
/* 8B2310 802422A0 8CC50000 */  lw        $a1, ($a2)
/* 8B2314 802422A4 3C068024 */  lui       $a2, 0x8024
/* 8B2318 802422A8 0C0B2026 */  jal       set_variable
/* 8B231C 802422AC 8CC67E34 */   lw       $a2, 0x7e34($a2)
/* 8B2320 802422B0 24020002 */  addiu     $v0, $zero, 2
.L802422B4:
/* 8B2324 802422B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2328 802422B8 03E00008 */  jr        $ra
/* 8B232C 802422BC 27BD0018 */   addiu    $sp, $sp, 0x18
